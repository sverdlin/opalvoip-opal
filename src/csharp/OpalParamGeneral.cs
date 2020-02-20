//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 4.0.1
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class OpalParamGeneral : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal OpalParamGeneral(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(OpalParamGeneral obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~OpalParamGeneral() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          OPALPINVOKE.delete_OpalParamGeneral(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public string audioRecordDevice {
    set {
      OPALPINVOKE.OpalParamGeneral_audioRecordDevice_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_audioRecordDevice_get(swigCPtr);
      return ret;
    } 
  }

  public string audioPlayerDevice {
    set {
      OPALPINVOKE.OpalParamGeneral_audioPlayerDevice_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_audioPlayerDevice_get(swigCPtr);
      return ret;
    } 
  }

  public string videoInputDevice {
    set {
      OPALPINVOKE.OpalParamGeneral_videoInputDevice_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_videoInputDevice_get(swigCPtr);
      return ret;
    } 
  }

  public string videoOutputDevice {
    set {
      OPALPINVOKE.OpalParamGeneral_videoOutputDevice_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_videoOutputDevice_get(swigCPtr);
      return ret;
    } 
  }

  public string videoPreviewDevice {
    set {
      OPALPINVOKE.OpalParamGeneral_videoPreviewDevice_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_videoPreviewDevice_get(swigCPtr);
      return ret;
    } 
  }

  public string mediaOrder {
    set {
      OPALPINVOKE.OpalParamGeneral_mediaOrder_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_mediaOrder_get(swigCPtr);
      return ret;
    } 
  }

  public string mediaMask {
    set {
      OPALPINVOKE.OpalParamGeneral_mediaMask_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_mediaMask_get(swigCPtr);
      return ret;
    } 
  }

  public string autoRxMedia {
    set {
      OPALPINVOKE.OpalParamGeneral_autoRxMedia_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_autoRxMedia_get(swigCPtr);
      return ret;
    } 
  }

  public string autoTxMedia {
    set {
      OPALPINVOKE.OpalParamGeneral_autoTxMedia_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_autoTxMedia_get(swigCPtr);
      return ret;
    } 
  }

  public string natMethod {
    set {
      OPALPINVOKE.OpalParamGeneral_natMethod_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_natMethod_get(swigCPtr);
      return ret;
    } 
  }

  public string natServer {
    set {
      OPALPINVOKE.OpalParamGeneral_natServer_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_natServer_get(swigCPtr);
      return ret;
    } 
  }

  public uint tcpPortBase {
    set {
      OPALPINVOKE.OpalParamGeneral_tcpPortBase_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_tcpPortBase_get(swigCPtr);
      return ret;
    } 
  }

  public uint tcpPortMax {
    set {
      OPALPINVOKE.OpalParamGeneral_tcpPortMax_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_tcpPortMax_get(swigCPtr);
      return ret;
    } 
  }

  public uint udpPortBase {
    set {
      OPALPINVOKE.OpalParamGeneral_udpPortBase_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_udpPortBase_get(swigCPtr);
      return ret;
    } 
  }

  public uint udpPortMax {
    set {
      OPALPINVOKE.OpalParamGeneral_udpPortMax_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_udpPortMax_get(swigCPtr);
      return ret;
    } 
  }

  public uint rtpPortBase {
    set {
      OPALPINVOKE.OpalParamGeneral_rtpPortBase_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_rtpPortBase_get(swigCPtr);
      return ret;
    } 
  }

  public uint rtpPortMax {
    set {
      OPALPINVOKE.OpalParamGeneral_rtpPortMax_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_rtpPortMax_get(swigCPtr);
      return ret;
    } 
  }

  public uint rtpTypeOfService {
    set {
      OPALPINVOKE.OpalParamGeneral_rtpTypeOfService_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_rtpTypeOfService_get(swigCPtr);
      return ret;
    } 
  }

  public uint rtpMaxPayloadSize {
    set {
      OPALPINVOKE.OpalParamGeneral_rtpMaxPayloadSize_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_rtpMaxPayloadSize_get(swigCPtr);
      return ret;
    } 
  }

  public uint minAudioJitter {
    set {
      OPALPINVOKE.OpalParamGeneral_minAudioJitter_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_minAudioJitter_get(swigCPtr);
      return ret;
    } 
  }

  public uint maxAudioJitter {
    set {
      OPALPINVOKE.OpalParamGeneral_maxAudioJitter_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_maxAudioJitter_get(swigCPtr);
      return ret;
    } 
  }

  public OpalSilenceDetectMode silenceDetectMode {
    set {
      OPALPINVOKE.OpalParamGeneral_silenceDetectMode_set(swigCPtr, (int)value);
    } 
    get {
      OpalSilenceDetectMode ret = (OpalSilenceDetectMode)OPALPINVOKE.OpalParamGeneral_silenceDetectMode_get(swigCPtr);
      return ret;
    } 
  }

  public uint silenceThreshold {
    set {
      OPALPINVOKE.OpalParamGeneral_silenceThreshold_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_silenceThreshold_get(swigCPtr);
      return ret;
    } 
  }

  public uint signalDeadband {
    set {
      OPALPINVOKE.OpalParamGeneral_signalDeadband_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_signalDeadband_get(swigCPtr);
      return ret;
    } 
  }

  public uint silenceDeadband {
    set {
      OPALPINVOKE.OpalParamGeneral_silenceDeadband_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_silenceDeadband_get(swigCPtr);
      return ret;
    } 
  }

  public uint silenceAdaptPeriod {
    set {
      OPALPINVOKE.OpalParamGeneral_silenceAdaptPeriod_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_silenceAdaptPeriod_get(swigCPtr);
      return ret;
    } 
  }

  public OpalEchoCancelMode echoCancellation {
    set {
      OPALPINVOKE.OpalParamGeneral_echoCancellation_set(swigCPtr, (int)value);
    } 
    get {
      OpalEchoCancelMode ret = (OpalEchoCancelMode)OPALPINVOKE.OpalParamGeneral_echoCancellation_get(swigCPtr);
      return ret;
    } 
  }

  public uint audioBuffers {
    set {
      OPALPINVOKE.OpalParamGeneral_audioBuffers_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_audioBuffers_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_f_p_q_const__char_p_q_const__char_p_q_const__char_p_void_p_void_int__int mediaReadData {
    set {
      OPALPINVOKE.OpalParamGeneral_mediaReadData_set(swigCPtr, SWIGTYPE_p_f_p_q_const__char_p_q_const__char_p_q_const__char_p_void_p_void_int__int.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = OPALPINVOKE.OpalParamGeneral_mediaReadData_get(swigCPtr);
      SWIGTYPE_p_f_p_q_const__char_p_q_const__char_p_q_const__char_p_void_p_void_int__int ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_p_q_const__char_p_q_const__char_p_q_const__char_p_void_p_void_int__int(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_f_p_q_const__char_p_q_const__char_p_q_const__char_p_void_p_void_int__int mediaWriteData {
    set {
      OPALPINVOKE.OpalParamGeneral_mediaWriteData_set(swigCPtr, SWIGTYPE_p_f_p_q_const__char_p_q_const__char_p_q_const__char_p_void_p_void_int__int.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = OPALPINVOKE.OpalParamGeneral_mediaWriteData_get(swigCPtr);
      SWIGTYPE_p_f_p_q_const__char_p_q_const__char_p_q_const__char_p_void_p_void_int__int ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_p_q_const__char_p_q_const__char_p_q_const__char_p_void_p_void_int__int(cPtr, false);
      return ret;
    } 
  }

  public OpalMediaDataType mediaDataHeader {
    set {
      OPALPINVOKE.OpalParamGeneral_mediaDataHeader_set(swigCPtr, (int)value);
    } 
    get {
      OpalMediaDataType ret = (OpalMediaDataType)OPALPINVOKE.OpalParamGeneral_mediaDataHeader_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_f_p_q_const__OpalMessage__int messageAvailable {
    set {
      OPALPINVOKE.OpalParamGeneral_messageAvailable_set(swigCPtr, SWIGTYPE_p_f_p_q_const__OpalMessage__int.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = OPALPINVOKE.OpalParamGeneral_messageAvailable_get(swigCPtr);
      SWIGTYPE_p_f_p_q_const__OpalMessage__int ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_p_q_const__OpalMessage__int(cPtr, false);
      return ret;
    } 
  }

  public string mediaOptions {
    set {
      OPALPINVOKE.OpalParamGeneral_mediaOptions_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_mediaOptions_get(swigCPtr);
      return ret;
    } 
  }

  public uint audioBufferTime {
    set {
      OPALPINVOKE.OpalParamGeneral_audioBufferTime_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_audioBufferTime_get(swigCPtr);
      return ret;
    } 
  }

  public uint manualAlerting {
    set {
      OPALPINVOKE.OpalParamGeneral_manualAlerting_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_manualAlerting_get(swigCPtr);
      return ret;
    } 
  }

  public OpalMediaTiming mediaTiming {
    set {
      OPALPINVOKE.OpalParamGeneral_mediaTiming_set(swigCPtr, (int)value);
    } 
    get {
      OpalMediaTiming ret = (OpalMediaTiming)OPALPINVOKE.OpalParamGeneral_mediaTiming_get(swigCPtr);
      return ret;
    } 
  }

  public OpalMediaTiming videoSourceTiming {
    set {
      OPALPINVOKE.OpalParamGeneral_videoSourceTiming_set(swigCPtr, (int)value);
    } 
    get {
      OpalMediaTiming ret = (OpalMediaTiming)OPALPINVOKE.OpalParamGeneral_videoSourceTiming_get(swigCPtr);
      return ret;
    } 
  }

  public string pcssMediaOverride {
    set {
      OPALPINVOKE.OpalParamGeneral_pcssMediaOverride_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_pcssMediaOverride_get(swigCPtr);
      return ret;
    } 
  }

  public uint noMediaTimeout {
    set {
      OPALPINVOKE.OpalParamGeneral_noMediaTimeout_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_noMediaTimeout_get(swigCPtr);
      return ret;
    } 
  }

  public string caFiles {
    set {
      OPALPINVOKE.OpalParamGeneral_caFiles_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_caFiles_get(swigCPtr);
      return ret;
    } 
  }

  public string certificate {
    set {
      OPALPINVOKE.OpalParamGeneral_certificate_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_certificate_get(swigCPtr);
      return ret;
    } 
  }

  public string privateKey {
    set {
      OPALPINVOKE.OpalParamGeneral_privateKey_set(swigCPtr, value);
    } 
    get {
      string ret = OPALPINVOKE.OpalParamGeneral_privateKey_get(swigCPtr);
      return ret;
    } 
  }

  public uint autoCreateCertificate {
    set {
      OPALPINVOKE.OpalParamGeneral_autoCreateCertificate_set(swigCPtr, value);
    } 
    get {
      uint ret = OPALPINVOKE.OpalParamGeneral_autoCreateCertificate_get(swigCPtr);
      return ret;
    } 
  }

  public OpalParamGeneral() : this(OPALPINVOKE.new_OpalParamGeneral(), true) {
  }

}
