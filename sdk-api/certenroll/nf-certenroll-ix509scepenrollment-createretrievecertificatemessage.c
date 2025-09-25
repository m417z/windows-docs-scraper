HRESULT CreateRetrieveCertificateMessage(
  [in]          X509CertificateEnrollmentContext Context,
  [in]          BSTR                             strIssuer,
  [in]          EncodingType                     IssuerEncoding,
  [in]          BSTR                             strSerialNumber,
  [in]          EncodingType                     SerialNumberEncoding,
  [in]          EncodingType                     Encoding,
  [out, retval] BSTR                             *pValue
);