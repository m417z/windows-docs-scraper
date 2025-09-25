HRESULT Initialize(
  [in] BSTR                             bstrPolicyServerUrl,
  [in] BSTR                             bstrPolicyServerId,
  [in] X509EnrollmentAuthFlags          authFlags,
  [in] VARIANT_BOOL                     fIsUnTrusted,
  [in] X509CertificateEnrollmentContext context
);