/*
 * README for IEEE 1394 digital camera support routine in PWLib
 * ------------------------------------------------------------
 * 
 * PWLib now contains preliminary support for the IEEE 1394 digital
 * cameras under Linux.
 * 
 * 
 * Supported cameras:
 * 
 * There are two kind of the specifications of IEEE 1394 digital video
 * cameras, one is called "digital camera" and another is "AV/C camera".
 * A digital camera sends uncompressed video data while an AV/C camera
 * sends compressed data. Currently PWLib only supports digital
 * cameras. We can find a list of supported digital cameras by the Linux
 * device driver at:
 * http://www.tele.ucl.ac.be/PEOPLE/DOUXCHAMPS/ieee1394/cameras/
 * 
 * AV/C cameras seem able to be used for video phone. You are welcome to
 * write supporting codes for AV/C cameras!
 * 
 * 
 * Installation and Use:
 * 
 * To enable 1394 camera support, you have to define the "TRY_1394DC"
 * shell environment variable at compilation time of PWLib, OpenH323, and
 * ohphone. To select your 1394 camera for video input device instead of
 * usual Video4Linux devices, specify "/dev/raw1394" or "/dev/video1394"
 * as the filename of video input device. For example "ohphone
 * --videoinput /dev/raw1394" should use your 1394 camera as video input.
 * 
 * "/dev/video1394" uses faster DMA transfer for video input.
 * 
 * If you use DEVFS, the filename for DMA transfer may be /dev/video1394/0.
 * 
 * Requirements for Installation:
 * 
 * You needs the following softwares to compile the 1394 camera support
 * module in PWLib.
 * 
 * - libdc1394 later than Feb. 1, 2002
 * - Linux 2.4.17 or later, which is required by the above version of
 *   libdc1394
 * - libraw1394 0.9.0 or later
 * 
 * You cannot compile it with older versions of libdc1394.
 * 
 * Troubleshooting:
 * 
 * If this module does not work for you, please verify the following
 * items before sending email:
 * 
 * 1) Can you view image of your camera by other programs? A sample
 *    program called "grab_gray_image" is included in the example
 *    directory of libdc1394. Please run grab_gray_image and see what
 *    happens. You can also use Coriander instead.
 *    (http://www.tele.ucl.ac.be/PEOPLE/DOUXCHAMPS/ieee1394/coriander/).
 * 2) If you have make sure other programs can use the camera, but
 *    this module still does not work, please run the debbuging version
 *    of ohphone with option "-tttt -o log.txt". Examine the file "log.txt"
 *    and you may see what is wrong.
 * 
 * 
 * Problem Reports:
 * They should be send to Ryutaroh Matsumoto <ryutaroh@rmatsumoto.org>.
 * 
 * 
 * Acknowledgment:
 * R. Matsumoto thanks Dr. Derek Smithies for his kind support for making
 * this module.
 * 
 * 
 * Technical Notes for Programmers
 * ------------------------------------------------------------
 *
 * Test Environment:
 * This module was tested against:
 *
 * Pentium III  
 * Linux 2.4.18
 * libraw1394 0.9.0
 * libdc1394 CVS version (Mar. 2, 2002)
 * pwlib 1.2.12
 * openh323 1.8.0
 * ohphone 1.2.0
 * GnomeMeeting 0.12.2
 *
 * Irez StealthFire Camera (http://www.irez.com)
 * OrangeMicro iBot Camera (http://www.orangemicro.com)
 *
 *
 * Internal Structure:
 * This module has been tested against the ohphone and GnomeMeeting
 * video phone programs. They use 352x288 and 176x144 resolutions in
 * YUV420P color format. So this module only supports these
 * resolutions and YUV420P.
 *
 * 1394 Digital Cameras has many resolutions and color formats. Among
 * them, this module uses:
 *	160x120 YUV(4:4:4)  for  176x144 PTlib resolution, and
 *	320x240 YUV(4:2:2)  for  352x288 PTlib resolution.
 * The bus speed is always set to P_DC1394_DEFAULT_SPEED (400 Mbps).
 * If transfer at P_DC1394_DEFAULT_SPEED is not supported by your
 * camera, this module does not capture images from yours. In such
 * a case please set P_DC1394_DEFAULT_SPEED to appropriate value.
 *
 * Conversion routines from above formats to YUV420P were added to
 * src/ptlib/common/vconvert.cxx
 *
 * ToDo or Bugs:
 * This module does not implement GetBrightness() etc.  1394 cameras
 * can do both automatic control and manual control of brightness
 * etc., and they are usually set to automatic
 * control. Get/SetBrightness() etc. cannot access manual/automatic
 * selection. So we cannot implement an interface that can fully
 * control all of 1394 camera features. I decided not to implement
 * controlling interface at all. Those features can be controlled by
 * Coriander program even when ohphone or GnomeMeeting is being used.
 * Please use Coriander.
 *
 * PVideoInput1394DcDevice does not allow creation of two or more instances.
 *
 * The bus speed is always set to P_DC1394_DEFAULT_SPEED (400 Mbps).
 * If transfer at P_DC1394_DEFAULT_SPEED is not supported by your
 * camera, this module does not capture images from yours. In such
 * a case please set P_DC1394_DEFAULT_SPEED to appropriate value.
 *
 * Copyright:
 * Copyright (c) 2002 Ryutaroh Matsumoto <ryutaroh@rmatsumoto.org>
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
 *
 *
 * $Log: video4dc1394.cxx,v $
 * Revision 1.7  2002/05/30 22:49:35  dereks
 * correct implementation of GetInputDeviceNames().
 *
 * Revision 1.6  2002/03/04 01:21:31  dereks
 * Add frame rate support to Firewire camera. Thanks Ryutaroh Matsumoto.
 *
 * Revision 1.5  2002/02/28 19:44:03  dereks
 * Add complete readme on Firewire usage. Thanks to Ryutaroh Matsumoto.
 *
 * Revision 1.4  2002/02/21 20:00:21  dereks
 * Fix memory leak. Thanks Ryutaroh Matsumoto.
 *
 * Revision 1.3  2002/02/21 19:49:57  dereks
 * Fix spelling mistake. Thanks Ryutaroh
 *
 * Revision 1.2  2002/02/20 20:27:28  dereks
 * updates to previous checkin.
 *
 * Revision 1.1  2002/02/20 02:37:26  dereks
 * Initial release of Firewire camera support for linux.
 * Many thanks to Ryutaroh Matsumoto <ryutaroh@rmatsumoto.org>.
 *
 *
 *
 *
 */

#pragma implementation "videoio1394dc.h"

#include <ptlib.h>
#include <ptlib/videoio.h>
#include <ptlib/videoio1394dc.h>
#include <ptlib/vconvert.h>
#include <ptlib/file.h>

#ifndef P_DC1394_DEFAULT_SPEED
#define P_DC1394_DEFAULT_SPEED  SPEED_400
#endif

//#define ESTIMATE_CAPTURE_PERFORMANCE

#ifdef ESTIMATE_CAPTURE_PERFORMANCE
// for debugging
static PInt64 start_time;
static int num_captured;
#endif


///////////////////////////////////////////////////////////////////////////////
// PVideoInput1394DC

PVideoInput1394DcDevice::PVideoInput1394DcDevice()
{
  handle = NULL;
  is_capturing = FALSE;
  capturing_duration = 10000; // arbitrary large value suffices
}

PVideoInput1394DcDevice::~PVideoInput1394DcDevice()
{
  Close();
}

BOOL PVideoInput1394DcDevice::Open(const PString & devName, BOOL startImmediate)
{
  if (IsOpen()) {
    PTRACE(0, "You cannot open PVideoInput1394DcDevice twice.");
    return FALSE;
  }

  if (devName == "/dev/raw1394")
    UseDMA = FALSE;
  // Don't forget /dev/video1394/0
  else if (strncmp(devName, "/dev/video1394", 14) == 0)
    UseDMA = TRUE;
  else {
    PTRACE(0, "devName must be /dev/raw1394 or /dev/video1394");
    return FALSE;
  }

  // See if devName is accessible.
  if (!PFile::Exists(devName)) {
    PTRACE(1, devName << " is not accessible.");
    return FALSE;
  }

  /*-----------------------------------------------------------------------
   *  Open ohci and asign handle to it
   *-----------------------------------------------------------------------*/
  handle = dc1394_create_handle(0);
  if (handle==NULL)
  {
    PTRACE(0, "Unable to aquire a raw1394 handle\n"
	   "did you insmod the drivers?\n");
    return FALSE;
  }

  /*-----------------------------------------------------------------------
   *  get the camera nodes and describe them as we find them
   *-----------------------------------------------------------------------*/
  int numNodes = raw1394_get_nodecount(handle);
  camera_nodes = dc1394_get_camera_nodes(handle,&numCameras,0);
  if (numCameras<1)
  {
    PTRACE(0, "no cameras found :(\n");
    raw1394_destroy_handle(handle);
    handle = NULL;
    return FALSE;
  }

  /*-----------------------------------------------------------------------
   *  to prevent the iso-transfer bug from raw1394 system, check if
   *  camera is highest node. For details see 
   *  http://linux1394.sourceforge.net/faq.html#DCbusmgmt
   *  and
   *  http://sourceforge.net/tracker/index.php?func=detail&aid=435107&group_id=8157&atid=108157
   *-----------------------------------------------------------------------*/
  for (int i=0; i<numCameras; i++) {
    if( camera_nodes[i] == numNodes-1) {
      PTRACE(0,"Sorry, your camera is the highest numbered node\n"
             "of the bus, and has therefore become the root node.\n"
             "The root node is responsible for maintaining \n"
             "the timing of isochronous transactions on the IEEE \n"
             "1394 bus.  However, if the root node is not cycle master \n"
             "capable (it doesn't have to be), then isochronous \n"
             "transactions will not work.  The host controller card is \n"
             "cycle master capable, however, most cameras are not.\n"
             "\n"
             "The quick solution is to add the parameter \n"
             "attempt_root=1 when loading the OHCI driver as a \n"
             "module.  So please do (as root):\n"
             "\n"
             "   rmmod ohci1394\n"
             "   insmod ohci1394 attempt_root=1\n"
             "\n"
             "for more information see the FAQ at \n"
             "http://linux1394.sourceforge.net/faq.html#DCbusmgmt\n"
             "\n");
      raw1394_destroy_handle(handle);
      handle = NULL;
      return FALSE;
    }
  }

  SetCanCaptureVideo(TRUE);
  frameHeight = 240;
  frameWidth = 320;
  colourFormat = "UYVY422";
  desiredFrameHeight = CIFHeight;
  desiredFrameWidth = CIFWidth;
  desiredColourFormat = "YUV420P";
  capturing_duration = 10000; // arbitrary large value suffices
  deviceName = devName;

  // select the specified input and video format
  if (!SetChannel(channelNumber) ||
      !SetVideoFormat(videoFormat)) {
    PTRACE(1, "SetChannel() or SetVideoFormat() failed");
    Close();
    return FALSE;
  }

  if (startImmediate && !Start()) {
    Close();
    return FALSE;
  }
  PTRACE(3, "Successfully opended\n");
  return TRUE;
}


BOOL PVideoInput1394DcDevice::IsOpen() 
{
  return handle != NULL;
}


BOOL PVideoInput1394DcDevice::Close()
{
  if (IsOpen()) {
    if (IsCapturing())
      Stop();
    raw1394_destroy_handle(handle);
    handle = NULL;
    return TRUE;
  } else
    return FALSE;
}

BOOL PVideoInput1394DcDevice::Start()
{
  int dc1394_mode;
  if (!IsOpen()) return FALSE;
  if (is_capturing) return TRUE;
  if (frameWidth == 320 && frameHeight == 240)
    dc1394_mode = MODE_320x240_YUV422;
  else if (frameWidth == 160 && frameHeight == 120)
    dc1394_mode = MODE_160x120_YUV444;
  else {
    PTRACE(1, "Frame size is neither 320x240 or 160x120" << frameWidth <<
	   "x" << frameHeight);
    return FALSE;
  }
  PTRACE(1, deviceName << " " << channelNumber);

  // In order to compile the following line, you need libdc1394 later than Feb. 1, 2002.
  camera.dma_device_file = deviceName.GetPointer();

  quadlet_t supported_framerates;
  if (dc1394_query_supported_framerates(handle, camera_nodes[channelNumber],
					FORMAT_VGA_NONCOMPRESSED, dc1394_mode,
					&supported_framerates) != DC1394_SUCCESS) {
    PTRACE(1, "dc1394_query_supported_framerates() failed.");
    return FALSE;
  }

  int framerate;

  // supported_framerates seems always in the network byte order.
  if (supported_framerates & (1U << (31-5)))
    framerate = FRAMERATE_60;
  else if (supported_framerates & (1U << (31-4)))
    framerate = FRAMERATE_30;
  else if (supported_framerates & (1U << (31-3)))
    framerate = FRAMERATE_15;
  else if (supported_framerates & (1U << (31-2)))
    framerate = FRAMERATE_7_5;
  else if (supported_framerates & (1U << (31-1)))
    framerate = FRAMERATE_3_75;
  else if (supported_framerates & (1U << (31-0)))
    framerate = FRAMERATE_1_875;
  else {
    PTRACE(1, "No supported frame rate??!!" << supported_framerates);
    return FALSE;
  }  

  if ((UseDMA &&dc1394_dma_setup_capture(handle,camera_nodes[channelNumber],
                           0, /* channel of IEEE 1394 */ 
                           FORMAT_VGA_NONCOMPRESSED,
                           dc1394_mode,
                           P_DC1394_DEFAULT_SPEED,
                           framerate, 4,
			 &camera)!=DC1394_SUCCESS) ||
      (!UseDMA && dc1394_setup_capture(handle,camera_nodes[channelNumber],
                           0, /* channel of IEEE 1394 */ 
                           FORMAT_VGA_NONCOMPRESSED,
                           dc1394_mode,
                           P_DC1394_DEFAULT_SPEED,
                           framerate,
		       &camera)!=DC1394_SUCCESS))
  {
    PTRACE(0,"unable to setup camera-\n"
             "check " __FILE__ " to make sure\n"
             "that the video mode,framerate and format are\n"
             "supported by your camera\n");
    return FALSE;
  }

  /*-----------------------------------------------------------------------
   *  have the camera start sending us data
   *-----------------------------------------------------------------------*/
  if (dc1394_start_iso_transmission(handle,camera.node)
      !=DC1394_SUCCESS) 
  {
    PTRACE(0, "unable to start camera iso transmission\n");
    if (UseDMA)
      dc1394_dma_release_camera(handle,&camera);
    else
      dc1394_release_camera(handle,&camera);
    return FALSE;
  }
  is_capturing = TRUE;
#ifdef ESTIMATE_CAPTURE_PERFORMANCE
  PTime now;
  start_time = now.GetTimestamp();
  num_captured = 0;
#endif
  return TRUE;
}


BOOL PVideoInput1394DcDevice::Stop()
{
  if (IsCapturing()) {
    dc1394_stop_iso_transmission(handle,camera.node);
    if (UseDMA) {
    dc1394_dma_unlisten(handle, &camera);
    dc1394_dma_release_camera(handle,&camera);
    } else
      dc1394_release_camera(handle,&camera);
    is_capturing = FALSE;
    return TRUE;
  } else
    return FALSE;
}


BOOL PVideoInput1394DcDevice::IsCapturing()
{
  return is_capturing;
}

PStringList PVideoInput1394DcDevice::GetInputDeviceNames()
{
  PStringList list;

  if (PFile::Exists("/dev/raw1394"))
    list.AppendString("/dev/raw1394");
  if (PFile::Exists("/dev/video1394/0"))
    // DEVFS naming scheme
    for (int i=0; ; i++) {
      PString devname = PString("/dev/video1394/") + PString(i);
      if (PFile::Exists(devname))
	list.AppendString(devname);
      else
	break;
    }
  else if (PFile::Exists("/dev/video1394"))
    /* traditional naming */
    list.AppendString("/dev/video1394");
  return list;
}


BOOL PVideoInput1394DcDevice::SetVideoFormat(VideoFormat newFormat)
{
  if (!PVideoDevice::SetVideoFormat(newFormat)) {
    PTRACE(3,"PVideoDevice::SetVideoFormat\t failed for format "<<newFormat);
    return FALSE;
  }
  return TRUE;
}

int PVideoInput1394DcDevice::GetBrightness()
{
  return -1;
}


BOOL PVideoInput1394DcDevice::SetBrightness(unsigned newBrightness)
{
  return FALSE;
}


int PVideoInput1394DcDevice::GetHue()
{
  return -1;
}


BOOL PVideoInput1394DcDevice::SetHue(unsigned newHue)
{
  return FALSE;
}


int PVideoInput1394DcDevice::GetContrast()
{
  return -1;
}


BOOL PVideoInput1394DcDevice::SetContrast(unsigned newContrast)
{
  return FALSE;
}

BOOL PVideoInput1394DcDevice::SetColour(unsigned newColour) 
{
  return -1;
}

int PVideoInput1394DcDevice::GetColour()
{
  return -1;
}


BOOL PVideoInput1394DcDevice::SetWhiteness(unsigned newWhiteness) 
{
  return FALSE;
}

int PVideoInput1394DcDevice::GetWhiteness()
{
  return -1;
}


BOOL PVideoInput1394DcDevice::GetParameters (int *whiteness, int *brightness,
                                       int *colour, int *contrast, int *hue)
{
  *whiteness = -1;
  *brightness = -1;
  *colour = -1;
  *hue = -1;
  return FALSE;
}


int PVideoInput1394DcDevice::GetNumChannels() 
{
  return numCameras;
}


BOOL PVideoInput1394DcDevice::SetChannel(int newChannel)
{
  if (PVideoDevice::SetChannel(newChannel) == FALSE)
    return FALSE;
  if(IsCapturing()) {
    Stop();
    Start();
  }
  return TRUE;
}



BOOL PVideoInput1394DcDevice::SetFrameRate(unsigned rate)
{
  return PVideoDevice::SetFrameRate(rate);
}


BOOL PVideoInput1394DcDevice::GetFrameSizeLimits(unsigned & minWidth,
                                           unsigned & minHeight,
                                           unsigned & maxWidth,
                                           unsigned & maxHeight) 
{
  minWidth = 160;
  maxWidth = 320;
  minHeight = 120;
  maxHeight = 240;
  return TRUE;
}



PINDEX PVideoInput1394DcDevice::GetMaxFrameBytes()
{
  if (converter != NULL) {
    PINDEX bytes = converter->GetMaxDstFrameBytes();
    if (bytes > frameBytes)
      return bytes;
  }

  return frameBytes;
}

BOOL PVideoInput1394DcDevice::GetFrameDataNoDelay(BYTE * buffer, PINDEX * bytesReturned)
{
  if (!IsCapturing()) return FALSE;

  if ((UseDMA && dc1394_dma_single_capture(&camera)!=DC1394_SUCCESS) ||
      (!UseDMA && dc1394_single_capture(handle,&camera)!=DC1394_SUCCESS)){
    PTRACE(1, "dc1394_single_capture() failed.");
    return FALSE;
  }
  
  PTRACE(3, "single captured, try to convert\n");

  // If converting on the fly do it from frame store to output buffer, otherwise do
  // straight copy.
  if (converter != NULL)
    converter->Convert((const BYTE *)camera.capture_buffer, buffer, bytesReturned);
  else {
    PTRACE(1, "Converter must exist. Something goes wrong.");
    return FALSE;
  }

#ifdef ESTIMATE_CAPTURE_PERFORMANCE
  ++num_captured;
  PTime now;
  double capturing_time = (double)((now.GetTimestamp()-start_time))/1000000;
  ::fprintf(stderr, "time %f, num_captured=%d, fps=%f\n",
	    capturing_time, num_captured, num_captured/capturing_time);
#endif

  if (UseDMA)
    dc1394_dma_done_with_buffer(&camera);
  return TRUE;
}

BOOL PVideoInput1394DcDevice::GetFrameData(BYTE * buffer, PINDEX * bytesReturned)
{
  if(frameRate>0) {
    if (msBetweenFrames > capturing_duration)
      PThread::Current()->Sleep(msBetweenFrames - capturing_duration);
    PTime start;
    if ( !GetFrameDataNoDelay(buffer, bytesReturned))
      return FALSE;
    PTime end;
    capturing_duration = (int)((end-start).GetMilliSeconds());
    return TRUE;
  }
  return GetFrameDataNoDelay(buffer,bytesReturned);
}


void PVideoInput1394DcDevice::ClearMapping()
{
}


BOOL PVideoInput1394DcDevice::TestAllFormats()
{
  return TRUE;
}

BOOL PVideoInput1394DcDevice::SetColourFormat(const PString & newFormat)
{
  if (newFormat != colourFormat) {
    return FALSE;
  }
  return TRUE;
}


BOOL PVideoInput1394DcDevice::SetFrameSize(unsigned width, unsigned height)
{
  if ((!(width == 320 && height == 240)) &&
      (!(width == 160 && height == 120)))
    return FALSE;

  frameWidth = width;
  frameHeight = height;

  if (frameWidth == 320 && frameHeight == 240)
    colourFormat = "UYVY422";
  else if (frameWidth == 160 && frameHeight == 120)
    colourFormat = "UYV444";

  frameBytes = PVideoDevice::CalculateFrameBytes(frameWidth, frameHeight, colourFormat);
  
  if (IsCapturing()) {
    Stop(); Start();
  }

  return TRUE;
}


BOOL PVideoInput1394DcDevice::SetFrameSizeConverter(unsigned width, unsigned height,
					 BOOL bScaleNotCrop)
{
  if (width == CIFWidth && height == CIFHeight)
    SetFrameSize(320, 240);
  else if (width == QCIFWidth && height == QCIFHeight)
    SetFrameSize(160, 120);
  else {
    PTRACE(1, width << "x" << height << " is not supported.");
    return FALSE;
  }

  if (converter != NULL) 
    delete converter;
  
  desiredFrameWidth = width;
  desiredFrameHeight = height;

  converter = PColourConverter::Create(colourFormat, desiredColourFormat, width, height);
  if (converter == NULL) {
    PTRACE(1, "Failed to make a converter.");
    return FALSE;
  }
  if (converter->SetSrcFrameSize(frameWidth, frameHeight) == FALSE) {
    PTRACE(1, "Failed to set source frame size of a converter.");
    return FALSE;
  }
  return TRUE;
}

BOOL PVideoInput1394DcDevice::SetColourFormatConverter(const PString & colourFmt)
{
  if (colourFmt != "YUV420P") {
    PTRACE(1, colourFmt << " is unsupported.");
    return FALSE;
  }
  desiredColourFormat = colourFmt;
  return SetFrameSizeConverter(desiredFrameWidth, desiredFrameHeight, FALSE);
}


    
// End Of File ///////////////////////////////////////////////////////////////
