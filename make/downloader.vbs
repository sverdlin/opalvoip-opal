'
' Contributor(s):
' Michael Jerris <mike@jerris.com>
' David A. Horner http://dave.thehorners.com
'----------------------------------------------

'On Error Resume Next
' **************
' Initialization
' **************

Set WshShell = CreateObject("WScript.Shell")
Set FSO = CreateObject("Scripting.FileSystemObject")
Set WshSysEnv = WshShell.Environment("SYSTEM")
Set xml = CreateObject("MSXML2.ServerXMLHTTP")
Dim UseWgetEXE

On Error Resume Next
Set oStream = CreateObject("Adodb.Stream")
On Error Goto 0

If Not IsObject(oStream)  Then
	wscript.echo("Failed to create Adodb.Stream, using alternative download method.")
	UseWgetEXE=true
Else
	UseWgetEXE=false
End If
Randomize
Set objArgs = WScript.Arguments
quote=Chr(34)
ScriptDir=Left(WScript.ScriptFullName,Len(WScript.ScriptFullName)-Len(WScript.ScriptName))
UtilsDir=Showpath(ScriptDir)
ToolsBase="http://files.freeswitch.org/downloads/win32/"

If UseWgetEXE Then
	GetWgetEXE UtilsDir
End If

GetCompressionTools UtilsDir


If objArgs.Count >=3 Then
	Select Case objArgs(0)
		Case "Get"		
			Wget objArgs(1), Showpath(objArgs(2))
		Case "GetUnzip"		
			WgetUnCompress objArgs(1), Showpath(objArgs(2))
	End Select
End If


' *******************
' Utility Subroutines
' *******************


Sub WgetUnCompress(URL, DestFolder)
	If Right(DestFolder, 1) <> "\" Then DestFolder = DestFolder & "\" End If
	StartPos = InstrRev(URL, "/", -1, 1) 
	strlength = Len(URL)
	filename=Right(URL,strlength-StartPos)
	NameEnd = InstrRev(filename, ".",-1, 1)
	filestrlength = Len(filename)
	filebase = Left(filename,NameEnd)
	fileext = Right(filename, Len(filename) - NameEnd)
	Wget URL, DestFolder
	If fileext = "zip" Then
		UnCompress Destfolder & filename, DestFolder & filebase
	Else
		UnCompress Destfolder & filename, DestFolder	
	End If
    FSO.DeleteFile Destfolder & filename, True
End Sub

Sub GetCompressionTools(DestFolder)
	Dim oExec
	If Right(DestFolder, 1) <> "\" Then DestFolder = DestFolder & "\" End If
	If Not FSO.FileExists(DestFolder & "7za.exe") Then 
		If Not FSO.FileExists(DestFolder & "7za.tag") Then 
			Set MyFile = fso.CreateTextFile(DestFolder & "7za.tag", True)
			MyFile.WriteLine("This file marks a pending download for 7za.exe so we don't download it twice at the same time")
			MyFile.Close
				
				Wget ToolsBase & "7za.exe", DestFolder
			
			FSO.DeleteFile DestFolder & "7za.tag" ,true 
		Else
			WScript.Sleep(5000)
		End If	
	End If	
End Sub

Sub GetWgetEXE(DestFolder)
	Dim oExec
	If Right(DestFolder, 1) <> "\" Then DestFolder = DestFolder & "\" End If
	If Not FSO.FileExists(DestFolder & "wget.exe") Then 
		Slow_Wget ToolsBase & "wget.exe", DestFolder
	End If	
End Sub

Sub UnCompress(CompressedArchive, DestFolder)
	wscript.echo("Decompressing: " & CompressedArchive)

	Set oExec = WshShell.Exec(quote & UtilsDir & "7za.exe" & quote & " x " & quote & CompressedArchive & quote & " -y -o" & quote & DestFolder & quote)
	Do
		WScript.Echo OExec.StdOut.ReadLine()
	Loop While Not OExec.StdOut.atEndOfStream

	WScript.Sleep(500)

	BaseArchive = Left(CompressedArchive, InStrRev(CompressedArchive, ".")-1)
	ExtractArchive BaseArchive, DestFolder
	ExtractArchive BaseArchive & "tar", DestFolder	
End Sub

Sub ExtractArchive(Archive, DestFolder)
	If FSO.FileExists(Archive)Then
		wscript.echo("Unpacking: " & Archive)
        IsArchive = True

		Set oExec = WshShell.Exec(quote & UtilsDir & "7za.exe" & quote & " x " & quote & Archive & quote & " -y -o" & quote & DestFolder & quote)
		Do
            Line = OExec.StdOut.ReadLine()
            If InStr(Line, "not supported archive") > 0 Then
                IsArchive = False
            Else
			    WScript.Echo Line
            End If
		Loop While Not OExec.StdOut.atEndOfStream

	    WScript.Sleep(500)

        If IsArchive Then
		    FSO.DeleteFile Archive, True
		    wscript.echo("Unpacked: " & Archive & " to " & DestFolder)
        Else
            FSO.MoveFile Archive, DestFolder
		    wscript.echo("Moved: " & Archive & " to " & DestFolder)
        End If
	End If
End Sub

Sub Wget(URL, DestFolder)
	StartPos = InStrRev(URL, "/", -1, 1)   
	strlength = Len(URL)
	filename=Right(URL,strlength-StartPos)
	If Right(DestFolder, 1) <> "\" Then
		DestFolder = DestFolder & "\"
	End If

	Wscript.echo("Downloading: " & URL)
	
	If UseWgetEXE Then
		batname = "tmp" & CStr(Int(10000*Rnd)) & ".bat"
		Set MyFile = fso.CreateTextFile(UtilsDir & batname, True)
		MyFile.WriteLine("@cd " & quote & DestFolder & quote)
		MyFile.WriteLine("@" & quote & UtilsDir & "wget.exe" & quote & " " & URL)
		MyFile.Close
		Set oExec = WshShell.Exec(UtilsDir & batname)
		Do
			WScript.Echo OExec.StdOut.ReadLine()
		Loop While Not OExec.StdOut.atEndOfStream
	Else
		xml.Open "GET", URL, False
		xml.Send
	
		Const adTypeBinary = 1
		Const adSaveCreateOverWrite = 2
		Const adSaveCreateNotExist = 1 

		oStream.type = adTypeBinary
		oStream.open
		oStream.write xml.responseBody
		oStream.savetofile DestFolder & filename, adSaveCreateOverWrite
		oStream.close
	End If
End Sub

Sub Slow_Wget(URL, DestFolder)
	StartPos = InstrRev(URL, "/", -1, 1)   
	strlength = Len(URL)
	filename=Right(URL,strlength-StartPos)
	If Right(DestFolder, 1) <> "\" Then
        DestFolder = DestFolder & "\"
    End If

	Wscript.echo("Downloading: " & URL)
	xml.Open "GET", URL, False
	xml.Send
	
	const ForReading = 1 , ForWriting = 2 , ForAppending = 8 
	Set MyFile = fso.OpenTextFile(DestFolder & filename ,ForWriting, True)
	For i = 1 to lenb(xml.responseBody)
	 MyFile.write Chr(Ascb(midb(xml.responseBody,i,1)))
	Next
	MyFile.Close()

End Sub

Function Showpath(folderspec)
	Set f = FSO.GetFolder(folderspec)
	showpath = f.path & "\"
End Function


