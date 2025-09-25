HRESULT InitializeFromCertificate(
  [in] X509CertificateEnrollmentContext Context,
  [in] VARIANT_BOOL                     RenewalRequest,
  [in] BSTR                             strCertificate,
  [in] EncodingType                     Encoding,
  [in] X509RequestInheritOptions        InheritOptions
);