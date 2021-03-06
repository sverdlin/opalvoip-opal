/*
 * main.cxx
 *
 * OPAL application source file for Interactive Voice Response using VXML
 *
 * Copyright (c) 2008 Vox Lucida Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Open Phone Abstraction Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 */

#include "precompile.h"
#include "main.h"


// Debug: -ttttodebugstream file:../callgen/ogm.wav sip:10.0.1.12
//        -ttttodebugstream "repeat=10;file:../callgen/ogm.wav"
//        -ttttodebugstream file:test.vxml


extern const char Manufacturer[] = "Vox Gratia";
extern const char Application[] = "OPAL IVR";
typedef OpalConsoleProcess<MyManager, Manufacturer, Application> MyApp;
PCREATE_PROCESS(MyApp);

#if OPAL_IVR

bool MyManager::Initialise(PArgList & args, bool verbose, const PString &)
{
  // Set up IVR
  MyIVREndPoint * ivr  = new MyIVREndPoint(*this);

  if (!OpalManagerConsole::Initialise(args, verbose, "ivr:") || args.GetCount() == 0)
    return false;

#if OPAL_HAS_PCSS
  FindEndPointAs<OpalLocalEndPoint>(OPAL_PCSS_PREFIX)->SetDeferredAnswer(false);
#endif

  ivr->SetDefaultVXML(args[0]);

  if (args.GetCount() == 1) {
    *LockedOutput() << "Awaiting incoming call, using VXML \"" << args[0] << "\" ... " << flush;
    return true;
  }

  bool atLeastOne = false;
  for (PINDEX i = 1; i < args.GetCount(); ++i) {
    PString token;
    if (SetUpCall("ivr:", args[i], token)) {
      *LockedOutput() << "Playing " << args[0] << " to " << args[i] << " token=" << token << endl;
      atLeastOne = true;
    }
    else
      *LockedOutput() << "Could not start call to \"" << args[i] << '"' << endl;
  }

  return atLeastOne;
}


void MyManager::Usage(ostream & strm, const PArgList & args)
{
  args.Usage(strm,
             "[ options ] vxml [ url ... ]") << "\n"
             "where vxml is a VXML script, a URL to a VXML script, or a WAV file, or a\n"
             "series of commands separated by ';'."
             "\n"
             "Commands are:\n"
             "  repeat=n    Repeat next WAV file n times.\n"
             "  delay=n     Delay after repeats n milliseconds.\n"
             "  voice=name  Set Text To Speech voice to name\n"
             "  tone=t      Emit DTMF tone t\n"
             "  silence=n   Emit silence for n milliseconds\n"
             "  speak=text  Speak the text using the Text To Speech system.\n"
             "  speak=$var  Speak the internal variable using the Text To Speech system.\n"
             "\n"
             "Variables may be one of:\n"
             "  Time\n"
             "  Originator-Address\n"
             "  Remote-Address\n"
             "  Source-IP-Address\n"
             "\n"
             "If a second parameter is provided and outgoing call is made and when answered\n"
             "the script is executed. If no second paramter is provided then the program\n"
             "will continuosly listen for incoming calls and execute the script on each\n"
             "call. Simultaneous calls to the limits of the operating system are possible.\n"
             "\n"
             "e.g. " << args.GetCommandName() << " file://message.wav sip:fred@bloggs.com\n"
             "     " << args.GetCommandName() << " http://voicemail.vxml\n"
             "     " << args.GetCommandName() << " \"repeat=5;delay=2000;speak=Hello, this is IVR!\"\n"
             "\n";

}


void MyManager::OnEstablishedCall(OpalCall & call)
{
  OpalManagerConsole::OnEstablishedCall(call);
#if OPAL_HAS_PCSS
  OpalPCSSConnection * pcss = call.GetConnectionAs<OpalPCSSConnection>();
  if (pcss != NULL) {
    PConsoleChannel * chan = new PConsoleChannel(PConsoleChannel::StandardInput);
    chan->SetLineBuffered(false);
    pcss->StartReadUserInput(chan);
  }
#endif // OPAL_HAS_PCSS
}


void MyManager::OnClearedCall(OpalCall & call)
{
  if (call.GetPartyA().NumCompare("ivr") == EqualTo)
    EndRun();
}


void MyIVREndPoint::OnEndDialog(OpalIVRConnection & connection)
{
  *dynamic_cast<MyManager &>(GetManager()).LockedOutput() << "\nFinal variables:\n" << connection.GetVXMLSession().GetVariables() << endl;

  // Do default action which is to clear the call.
  OpalIVREndPoint::OnEndDialog(connection);
}

#else

  #pragma message("Cannot compile IVR test program without OPAL_IVR set!")

#endif

// End of File ///////////////////////////////////////////////////////////////
