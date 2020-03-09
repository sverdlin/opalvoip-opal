/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.opalvoip.opal;

public class OpalStatusMessageWaiting {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected OpalStatusMessageWaiting(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(OpalStatusMessageWaiting obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        OPALJNI.delete_OpalStatusMessageWaiting(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setParty(String value) {
    OPALJNI.OpalStatusMessageWaiting_party_set(swigCPtr, this, value);
  }

  public String getParty() {
    return OPALJNI.OpalStatusMessageWaiting_party_get(swigCPtr, this);
  }

  public void setType(String value) {
    OPALJNI.OpalStatusMessageWaiting_type_set(swigCPtr, this, value);
  }

  public String getType() {
    return OPALJNI.OpalStatusMessageWaiting_type_get(swigCPtr, this);
  }

  public void setExtraInfo(String value) {
    OPALJNI.OpalStatusMessageWaiting_extraInfo_set(swigCPtr, this, value);
  }

  public String getExtraInfo() {
    return OPALJNI.OpalStatusMessageWaiting_extraInfo_get(swigCPtr, this);
  }

  public OpalStatusMessageWaiting() {
    this(OPALJNI.new_OpalStatusMessageWaiting(), true);
  }

}
