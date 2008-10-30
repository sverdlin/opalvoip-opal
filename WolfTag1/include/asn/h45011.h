//
// h45011.h
//
// Code automatically generated by asnparse.
//

#if ! H323_DISABLE_H45011

#ifndef __H45011_H
#define __H45011_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <ptclib/asner.h>

#include "h225.h"
#include "h4504.h"
#include "h4501.h"
#include "h4506.h"
#include "h45010.h"


//
// H323CallIntrusionOperations
//

class H45011_H323CallIntrusionOperations : public PASN_Enumeration
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_H323CallIntrusionOperations, PASN_Enumeration);
#endif
  public:
    H45011_H323CallIntrusionOperations(unsigned tag = UniversalEnumeration, TagClass tagClass = UniversalTagClass);

    enum Enumerations {
      e_callIntrusionRequest = 43,
      e_callIntrusionGetCIPL,
      e_callIntrusionIsolate,
      e_callIntrusionForcedRelease,
      e_callIntrusionWOBRequest,
      e_callIntrusionSilentMonitor = 116,
      e_callIntrusionNotification
    };

    H45011_H323CallIntrusionOperations & operator=(unsigned v);
    PObject * Clone() const;
};


//
// CICapabilityLevel
//

class H45011_CICapabilityLevel : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CICapabilityLevel, PASN_Integer);
#endif
  public:
    H45011_CICapabilityLevel(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    H45011_CICapabilityLevel & operator=(int v);
    H45011_CICapabilityLevel & operator=(unsigned v);
    PObject * Clone() const;
};


//
// CIProtectionLevel
//

class H45011_CIProtectionLevel : public PASN_Integer
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIProtectionLevel, PASN_Integer);
#endif
  public:
    H45011_CIProtectionLevel(unsigned tag = UniversalInteger, TagClass tagClass = UniversalTagClass);

    H45011_CIProtectionLevel & operator=(int v);
    H45011_CIProtectionLevel & operator=(unsigned v);
    PObject * Clone() const;
};


//
// CIStatusInformation
//

class H45011_CIStatusInformation : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIStatusInformation, PASN_Choice);
#endif
  public:
    H45011_CIStatusInformation(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_callIntrusionImpending,
      e_callIntruded,
      e_callIsolated,
      e_callForceReleased,
      e_callIntrusionComplete,
      e_callIntrusionEnd
    };

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// CallIntrusionErrors
//

class H45011_CallIntrusionErrors : public PASN_Enumeration
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CallIntrusionErrors, PASN_Enumeration);
#endif
  public:
    H45011_CallIntrusionErrors(unsigned tag = UniversalEnumeration, TagClass tagClass = UniversalTagClass);

    enum Enumerations {
      e_notBusy = 1009,
      e_temporarilyUnavailable = 1000,
      e_notAuthorized = 1007
    };

    H45011_CallIntrusionErrors & operator=(unsigned v);
    PObject * Clone() const;
};


//
// ArrayOf_MixedExtension
//

class H4504_MixedExtension;

class H45011_ArrayOf_MixedExtension : public PASN_Array
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_ArrayOf_MixedExtension, PASN_Array);
#endif
  public:
    H45011_ArrayOf_MixedExtension(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    PASN_Object * CreateObject() const;
    H4504_MixedExtension & operator[](PINDEX i) const;
    PObject * Clone() const;
};


//
// CIRequestArg
//

class H45011_CIRequestArg : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIRequestArg, PASN_Sequence);
#endif
  public:
    H45011_CIRequestArg(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_argumentExtension
    };

    H45011_CICapabilityLevel m_ciCapabilityLevel;
    H45011_ArrayOf_MixedExtension m_argumentExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIRequestRes
//

class H45011_CIRequestRes : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIRequestRes, PASN_Sequence);
#endif
  public:
    H45011_CIRequestRes(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_resultExtension
    };

    H45011_CIStatusInformation m_ciStatusInformation;
    H45011_ArrayOf_MixedExtension m_resultExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIGetCIPLOptArg
//

class H45011_CIGetCIPLOptArg : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIGetCIPLOptArg, PASN_Sequence);
#endif
  public:
    H45011_CIGetCIPLOptArg(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_argumentExtension
    };

    H45011_ArrayOf_MixedExtension m_argumentExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIGetCIPLRes
//

class H45011_CIGetCIPLRes : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIGetCIPLRes, PASN_Sequence);
#endif
  public:
    H45011_CIGetCIPLRes(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_silentMonitoringPermitted,
      e_resultExtension
    };

    H45011_CIProtectionLevel m_ciProtectionLevel;
    PASN_Null m_silentMonitoringPermitted;
    H45011_ArrayOf_MixedExtension m_resultExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIIsOptArg
//

class H45011_CIIsOptArg : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIIsOptArg, PASN_Sequence);
#endif
  public:
    H45011_CIIsOptArg(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_argumentExtension
    };

    H45011_ArrayOf_MixedExtension m_argumentExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIIsOptRes
//

class H45011_CIIsOptRes : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIIsOptRes, PASN_Sequence);
#endif
  public:
    H45011_CIIsOptRes(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_resultExtension
    };

    H45011_ArrayOf_MixedExtension m_resultExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIFrcRelArg
//

class H45011_CIFrcRelArg : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIFrcRelArg, PASN_Sequence);
#endif
  public:
    H45011_CIFrcRelArg(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_argumentExtension
    };

    H45011_CICapabilityLevel m_ciCapabilityLevel;
    H45011_ArrayOf_MixedExtension m_argumentExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIFrcRelOptRes
//

class H45011_CIFrcRelOptRes : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIFrcRelOptRes, PASN_Sequence);
#endif
  public:
    H45011_CIFrcRelOptRes(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_resultExtension
    };

    H45011_ArrayOf_MixedExtension m_resultExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIWobOptArg
//

class H45011_CIWobOptArg : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIWobOptArg, PASN_Sequence);
#endif
  public:
    H45011_CIWobOptArg(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_argumentExtension
    };

    H45011_ArrayOf_MixedExtension m_argumentExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CIWobOptRes
//

class H45011_CIWobOptRes : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CIWobOptRes, PASN_Sequence);
#endif
  public:
    H45011_CIWobOptRes(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_resultExtension
    };

    H45011_ArrayOf_MixedExtension m_resultExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CISilentArg
//

class H45011_CISilentArg : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CISilentArg, PASN_Sequence);
#endif
  public:
    H45011_CISilentArg(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_specificCall,
      e_argumentExtension
    };

    H45011_CICapabilityLevel m_ciCapabilityLevel;
    H225_CallIdentifier m_specificCall;
    H45011_ArrayOf_MixedExtension m_argumentExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CISilentOptRes
//

class H45011_CISilentOptRes : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CISilentOptRes, PASN_Sequence);
#endif
  public:
    H45011_CISilentOptRes(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_resultExtension
    };

    H45011_ArrayOf_MixedExtension m_resultExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// CINotificationArg
//

class H45011_CINotificationArg : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H45011_CINotificationArg, PASN_Sequence);
#endif
  public:
    H45011_CINotificationArg(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_argumentExtension
    };

    H45011_CIStatusInformation m_ciStatusInformation;
    H45011_ArrayOf_MixedExtension m_argumentExtension;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


#endif // __H45011_H

#endif // if ! H323_DISABLE_H45011


// End of h45011.h
