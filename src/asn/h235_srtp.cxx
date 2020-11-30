//
// h235_srtp.cxx
//
// Code automatically generated by asnparse.
//

#ifdef P_USE_PRAGMA
#pragma implementation "h235_srtp.h"
#endif

#include <ptlib.h>
#include "asn/h235_srtp.h"
#include "asn/h225.h"

#define new PNEW


#if ! H323_DISABLE_H235_SRTP

//
// SrtpCryptoCapability
//

H235_SRTP_SrtpCryptoCapability::H235_SRTP_SrtpCryptoCapability(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Array(tag, tagClass)
{
}


PASN_Object * H235_SRTP_SrtpCryptoCapability::CreateObject() const
{
  return new H235_SRTP_SrtpCryptoInfo;
}


H235_SRTP_SrtpCryptoInfo & H235_SRTP_SrtpCryptoCapability::operator[](PINDEX i) const
{
  return (H235_SRTP_SrtpCryptoInfo &)array[i];
}


PObject * H235_SRTP_SrtpCryptoCapability::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_SrtpCryptoCapability::Class()), PInvalidCast);
#endif
  return new H235_SRTP_SrtpCryptoCapability(*this);
}


//
// SrtpKeys
//

H235_SRTP_SrtpKeys::H235_SRTP_SrtpKeys(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Array(tag, tagClass)
{
}


PASN_Object * H235_SRTP_SrtpKeys::CreateObject() const
{
  return new H235_SRTP_SrtpKeyParameters;
}


H235_SRTP_SrtpKeyParameters & H235_SRTP_SrtpKeys::operator[](PINDEX i) const
{
  return (H235_SRTP_SrtpKeyParameters &)array[i];
}


PObject * H235_SRTP_SrtpKeys::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_SrtpKeys::Class()), PInvalidCast);
#endif
  return new H235_SRTP_SrtpKeys(*this);
}


//
// FecOrder
//

H235_SRTP_FecOrder::H235_SRTP_FecOrder(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 2, true, 0)
{
}


#ifndef PASN_NOPRINTON
void H235_SRTP_FecOrder::PrintOn(ostream & strm) const
{
  std::streamsize indent = strm.precision() + 2;
  strm << "{\n";
  if (HasOptionalField(e_fecBeforeSrtp))
    strm << setw(indent+16) << "fecBeforeSrtp = " << setprecision(indent) << m_fecBeforeSrtp << '\n';
  if (HasOptionalField(e_fecAfterSrtp))
    strm << setw(indent+15) << "fecAfterSrtp = " << setprecision(indent) << m_fecAfterSrtp << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison H235_SRTP_FecOrder::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, H235_SRTP_FecOrder), PInvalidCast);
#endif
  const H235_SRTP_FecOrder & other = (const H235_SRTP_FecOrder &)obj;

  Comparison result;

  if ((result = m_fecBeforeSrtp.Compare(other.m_fecBeforeSrtp)) != EqualTo)
    return result;
  if ((result = m_fecAfterSrtp.Compare(other.m_fecAfterSrtp)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX H235_SRTP_FecOrder::GetDataLength() const
{
  PINDEX length = 0;
  if (HasOptionalField(e_fecBeforeSrtp))
    length += m_fecBeforeSrtp.GetObjectLength();
  if (HasOptionalField(e_fecAfterSrtp))
    length += m_fecAfterSrtp.GetObjectLength();
  return length;
}


PBoolean H235_SRTP_FecOrder::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return false;

  if (HasOptionalField(e_fecBeforeSrtp) && !m_fecBeforeSrtp.Decode(strm))
    return false;
  if (HasOptionalField(e_fecAfterSrtp) && !m_fecAfterSrtp.Decode(strm))
    return false;

  return UnknownExtensionsDecode(strm);
}


void H235_SRTP_FecOrder::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  if (HasOptionalField(e_fecBeforeSrtp))
    m_fecBeforeSrtp.Encode(strm);
  if (HasOptionalField(e_fecAfterSrtp))
    m_fecAfterSrtp.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * H235_SRTP_FecOrder::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_FecOrder::Class()), PInvalidCast);
#endif
  return new H235_SRTP_FecOrder(*this);
}



#ifndef PASN_NOPRINTON
const static PASN_Names Names_H235_SRTP_SrtpKeyParameters_lifetime[]={
      {"powerOfTwo",0}
     ,{"specific",1}
};
#endif
//
// SrtpKeyParameters_lifetime
//

H235_SRTP_SrtpKeyParameters_lifetime::H235_SRTP_SrtpKeyParameters_lifetime(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Choice(tag, tagClass, 2, true
#ifndef PASN_NOPRINTON
    ,(const PASN_Names *)Names_H235_SRTP_SrtpKeyParameters_lifetime,2
#endif
)
{
}


PBoolean H235_SRTP_SrtpKeyParameters_lifetime::CreateObject()
{
  switch (m_tag) {
    case e_powerOfTwo :
    case e_specific :
      choice = new PASN_Integer();
      return true;
  }

  choice = NULL;
  return false;
}


PObject * H235_SRTP_SrtpKeyParameters_lifetime::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_SrtpKeyParameters_lifetime::Class()), PInvalidCast);
#endif
  return new H235_SRTP_SrtpKeyParameters_lifetime(*this);
}


//
// SrtpKeyParameters_mki
//

H235_SRTP_SrtpKeyParameters_mki::H235_SRTP_SrtpKeyParameters_mki(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 0, true, 0)
{
  m_length.SetConstraints(PASN_Object::FixedConstraint, 1, 128);
}


#ifndef PASN_NOPRINTON
void H235_SRTP_SrtpKeyParameters_mki::PrintOn(ostream & strm) const
{
  std::streamsize indent = strm.precision() + 2;
  strm << "{\n";
  strm << setw(indent+9) << "length = " << setprecision(indent) << m_length << '\n';
  strm << setw(indent+8) << "value = " << setprecision(indent) << m_value << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison H235_SRTP_SrtpKeyParameters_mki::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, H235_SRTP_SrtpKeyParameters_mki), PInvalidCast);
#endif
  const H235_SRTP_SrtpKeyParameters_mki & other = (const H235_SRTP_SrtpKeyParameters_mki &)obj;

  Comparison result;

  if ((result = m_length.Compare(other.m_length)) != EqualTo)
    return result;
  if ((result = m_value.Compare(other.m_value)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX H235_SRTP_SrtpKeyParameters_mki::GetDataLength() const
{
  PINDEX length = 0;
  length += m_length.GetObjectLength();
  length += m_value.GetObjectLength();
  return length;
}


PBoolean H235_SRTP_SrtpKeyParameters_mki::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return false;

  if (!m_length.Decode(strm))
    return false;
  if (!m_value.Decode(strm))
    return false;

  return UnknownExtensionsDecode(strm);
}


void H235_SRTP_SrtpKeyParameters_mki::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  m_length.Encode(strm);
  m_value.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * H235_SRTP_SrtpKeyParameters_mki::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_SrtpKeyParameters_mki::Class()), PInvalidCast);
#endif
  return new H235_SRTP_SrtpKeyParameters_mki(*this);
}


//
// ArrayOf_GenericData
//

H235_SRTP_ArrayOf_GenericData::H235_SRTP_ArrayOf_GenericData(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Array(tag, tagClass)
{
}


PASN_Object * H235_SRTP_ArrayOf_GenericData::CreateObject() const
{
  return new H225_GenericData;
}


H225_GenericData & H235_SRTP_ArrayOf_GenericData::operator[](PINDEX i) const
{
  return (H225_GenericData &)array[i];
}


PObject * H235_SRTP_ArrayOf_GenericData::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_ArrayOf_GenericData::Class()), PInvalidCast);
#endif
  return new H235_SRTP_ArrayOf_GenericData(*this);
}


//
// SrtpKeyParameters
//

H235_SRTP_SrtpKeyParameters::H235_SRTP_SrtpKeyParameters(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 2, true, 0)
{
}


#ifndef PASN_NOPRINTON
void H235_SRTP_SrtpKeyParameters::PrintOn(ostream & strm) const
{
  std::streamsize indent = strm.precision() + 2;
  strm << "{\n";
  strm << setw(indent+12) << "masterKey = " << setprecision(indent) << m_masterKey << '\n';
  strm << setw(indent+13) << "masterSalt = " << setprecision(indent) << m_masterSalt << '\n';
  if (HasOptionalField(e_lifetime))
    strm << setw(indent+11) << "lifetime = " << setprecision(indent) << m_lifetime << '\n';
  if (HasOptionalField(e_mki))
    strm << setw(indent+6) << "mki = " << setprecision(indent) << m_mki << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison H235_SRTP_SrtpKeyParameters::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, H235_SRTP_SrtpKeyParameters), PInvalidCast);
#endif
  const H235_SRTP_SrtpKeyParameters & other = (const H235_SRTP_SrtpKeyParameters &)obj;

  Comparison result;

  if ((result = m_masterKey.Compare(other.m_masterKey)) != EqualTo)
    return result;
  if ((result = m_masterSalt.Compare(other.m_masterSalt)) != EqualTo)
    return result;
  if ((result = m_lifetime.Compare(other.m_lifetime)) != EqualTo)
    return result;
  if ((result = m_mki.Compare(other.m_mki)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX H235_SRTP_SrtpKeyParameters::GetDataLength() const
{
  PINDEX length = 0;
  length += m_masterKey.GetObjectLength();
  length += m_masterSalt.GetObjectLength();
  if (HasOptionalField(e_lifetime))
    length += m_lifetime.GetObjectLength();
  if (HasOptionalField(e_mki))
    length += m_mki.GetObjectLength();
  return length;
}


PBoolean H235_SRTP_SrtpKeyParameters::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return false;

  if (!m_masterKey.Decode(strm))
    return false;
  if (!m_masterSalt.Decode(strm))
    return false;
  if (HasOptionalField(e_lifetime) && !m_lifetime.Decode(strm))
    return false;
  if (HasOptionalField(e_mki) && !m_mki.Decode(strm))
    return false;

  return UnknownExtensionsDecode(strm);
}


void H235_SRTP_SrtpKeyParameters::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  m_masterKey.Encode(strm);
  m_masterSalt.Encode(strm);
  if (HasOptionalField(e_lifetime))
    m_lifetime.Encode(strm);
  if (HasOptionalField(e_mki))
    m_mki.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * H235_SRTP_SrtpKeyParameters::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_SrtpKeyParameters::Class()), PInvalidCast);
#endif
  return new H235_SRTP_SrtpKeyParameters(*this);
}


//
// SrtpSessionParameters
//

H235_SRTP_SrtpSessionParameters::H235_SRTP_SrtpSessionParameters(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 7, true, 0)
{
  m_kdr.SetConstraints(PASN_Object::FixedConstraint, 0, 24);
  m_windowSizeHint.SetConstraints(PASN_Object::FixedConstraint, 64, 65535);
}


#ifndef PASN_NOPRINTON
void H235_SRTP_SrtpSessionParameters::PrintOn(ostream & strm) const
{
  std::streamsize indent = strm.precision() + 2;
  strm << "{\n";
  if (HasOptionalField(e_kdr))
    strm << setw(indent+6) << "kdr = " << setprecision(indent) << m_kdr << '\n';
  if (HasOptionalField(e_unencryptedSrtp))
    strm << setw(indent+18) << "unencryptedSrtp = " << setprecision(indent) << m_unencryptedSrtp << '\n';
  if (HasOptionalField(e_unencryptedSrtcp))
    strm << setw(indent+19) << "unencryptedSrtcp = " << setprecision(indent) << m_unencryptedSrtcp << '\n';
  if (HasOptionalField(e_unauthenticatedSrtp))
    strm << setw(indent+22) << "unauthenticatedSrtp = " << setprecision(indent) << m_unauthenticatedSrtp << '\n';
  if (HasOptionalField(e_fecOrder))
    strm << setw(indent+11) << "fecOrder = " << setprecision(indent) << m_fecOrder << '\n';
  if (HasOptionalField(e_windowSizeHint))
    strm << setw(indent+17) << "windowSizeHint = " << setprecision(indent) << m_windowSizeHint << '\n';
  if (HasOptionalField(e_newParameter))
    strm << setw(indent+15) << "newParameter = " << setprecision(indent) << m_newParameter << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison H235_SRTP_SrtpSessionParameters::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, H235_SRTP_SrtpSessionParameters), PInvalidCast);
#endif
  const H235_SRTP_SrtpSessionParameters & other = (const H235_SRTP_SrtpSessionParameters &)obj;

  Comparison result;

  if ((result = m_kdr.Compare(other.m_kdr)) != EqualTo)
    return result;
  if ((result = m_unencryptedSrtp.Compare(other.m_unencryptedSrtp)) != EqualTo)
    return result;
  if ((result = m_unencryptedSrtcp.Compare(other.m_unencryptedSrtcp)) != EqualTo)
    return result;
  if ((result = m_unauthenticatedSrtp.Compare(other.m_unauthenticatedSrtp)) != EqualTo)
    return result;
  if ((result = m_fecOrder.Compare(other.m_fecOrder)) != EqualTo)
    return result;
  if ((result = m_windowSizeHint.Compare(other.m_windowSizeHint)) != EqualTo)
    return result;
  if ((result = m_newParameter.Compare(other.m_newParameter)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX H235_SRTP_SrtpSessionParameters::GetDataLength() const
{
  PINDEX length = 0;
  if (HasOptionalField(e_kdr))
    length += m_kdr.GetObjectLength();
  if (HasOptionalField(e_unencryptedSrtp))
    length += m_unencryptedSrtp.GetObjectLength();
  if (HasOptionalField(e_unencryptedSrtcp))
    length += m_unencryptedSrtcp.GetObjectLength();
  if (HasOptionalField(e_unauthenticatedSrtp))
    length += m_unauthenticatedSrtp.GetObjectLength();
  if (HasOptionalField(e_fecOrder))
    length += m_fecOrder.GetObjectLength();
  if (HasOptionalField(e_windowSizeHint))
    length += m_windowSizeHint.GetObjectLength();
  if (HasOptionalField(e_newParameter))
    length += m_newParameter.GetObjectLength();
  return length;
}


PBoolean H235_SRTP_SrtpSessionParameters::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return false;

  if (HasOptionalField(e_kdr) && !m_kdr.Decode(strm))
    return false;
  if (HasOptionalField(e_unencryptedSrtp) && !m_unencryptedSrtp.Decode(strm))
    return false;
  if (HasOptionalField(e_unencryptedSrtcp) && !m_unencryptedSrtcp.Decode(strm))
    return false;
  if (HasOptionalField(e_unauthenticatedSrtp) && !m_unauthenticatedSrtp.Decode(strm))
    return false;
  if (HasOptionalField(e_fecOrder) && !m_fecOrder.Decode(strm))
    return false;
  if (HasOptionalField(e_windowSizeHint) && !m_windowSizeHint.Decode(strm))
    return false;
  if (HasOptionalField(e_newParameter) && !m_newParameter.Decode(strm))
    return false;

  return UnknownExtensionsDecode(strm);
}


void H235_SRTP_SrtpSessionParameters::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  if (HasOptionalField(e_kdr))
    m_kdr.Encode(strm);
  if (HasOptionalField(e_unencryptedSrtp))
    m_unencryptedSrtp.Encode(strm);
  if (HasOptionalField(e_unencryptedSrtcp))
    m_unencryptedSrtcp.Encode(strm);
  if (HasOptionalField(e_unauthenticatedSrtp))
    m_unauthenticatedSrtp.Encode(strm);
  if (HasOptionalField(e_fecOrder))
    m_fecOrder.Encode(strm);
  if (HasOptionalField(e_windowSizeHint))
    m_windowSizeHint.Encode(strm);
  if (HasOptionalField(e_newParameter))
    m_newParameter.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * H235_SRTP_SrtpSessionParameters::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_SrtpSessionParameters::Class()), PInvalidCast);
#endif
  return new H235_SRTP_SrtpSessionParameters(*this);
}


//
// SrtpCryptoInfo
//

H235_SRTP_SrtpCryptoInfo::H235_SRTP_SrtpCryptoInfo(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 3, true, 0)
{
}


#ifndef PASN_NOPRINTON
void H235_SRTP_SrtpCryptoInfo::PrintOn(ostream & strm) const
{
  std::streamsize indent = strm.precision() + 2;
  strm << "{\n";
  if (HasOptionalField(e_cryptoSuite))
    strm << setw(indent+14) << "cryptoSuite = " << setprecision(indent) << m_cryptoSuite << '\n';
  if (HasOptionalField(e_sessionParams))
    strm << setw(indent+16) << "sessionParams = " << setprecision(indent) << m_sessionParams << '\n';
  if (HasOptionalField(e_allowMKI))
    strm << setw(indent+11) << "allowMKI = " << setprecision(indent) << m_allowMKI << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison H235_SRTP_SrtpCryptoInfo::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, H235_SRTP_SrtpCryptoInfo), PInvalidCast);
#endif
  const H235_SRTP_SrtpCryptoInfo & other = (const H235_SRTP_SrtpCryptoInfo &)obj;

  Comparison result;

  if ((result = m_cryptoSuite.Compare(other.m_cryptoSuite)) != EqualTo)
    return result;
  if ((result = m_sessionParams.Compare(other.m_sessionParams)) != EqualTo)
    return result;
  if ((result = m_allowMKI.Compare(other.m_allowMKI)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX H235_SRTP_SrtpCryptoInfo::GetDataLength() const
{
  PINDEX length = 0;
  if (HasOptionalField(e_cryptoSuite))
    length += m_cryptoSuite.GetObjectLength();
  if (HasOptionalField(e_sessionParams))
    length += m_sessionParams.GetObjectLength();
  if (HasOptionalField(e_allowMKI))
    length += m_allowMKI.GetObjectLength();
  return length;
}


PBoolean H235_SRTP_SrtpCryptoInfo::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return false;

  if (HasOptionalField(e_cryptoSuite) && !m_cryptoSuite.Decode(strm))
    return false;
  if (HasOptionalField(e_sessionParams) && !m_sessionParams.Decode(strm))
    return false;
  if (HasOptionalField(e_allowMKI) && !m_allowMKI.Decode(strm))
    return false;

  return UnknownExtensionsDecode(strm);
}


void H235_SRTP_SrtpCryptoInfo::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  if (HasOptionalField(e_cryptoSuite))
    m_cryptoSuite.Encode(strm);
  if (HasOptionalField(e_sessionParams))
    m_sessionParams.Encode(strm);
  if (HasOptionalField(e_allowMKI))
    m_allowMKI.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * H235_SRTP_SrtpCryptoInfo::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H235_SRTP_SrtpCryptoInfo::Class()), PInvalidCast);
#endif
  return new H235_SRTP_SrtpCryptoInfo(*this);
}


#endif // if ! H323_DISABLE_H235_SRTP


// End of h235_srtp.cxx
