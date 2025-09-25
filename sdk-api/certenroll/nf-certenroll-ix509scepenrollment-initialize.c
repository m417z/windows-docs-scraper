HRESULT Initialize(
  [in] IX509CertificateRequestPkcs10 *pRequest,
  [in] BSTR                          strThumbprint,
  [in] EncodingType                  ThumprintEncoding,
  [in] BSTR                          strServerCertificates,
  [in] EncodingType                  Encoding
);