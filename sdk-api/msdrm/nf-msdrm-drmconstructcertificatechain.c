DRMEXPORT HRESULT UDAPICALL DRMConstructCertificateChain(
  [in]      UINT  cCertificates,
  [in]      PWSTR *rgwszCertificates,
  [in, out] UINT  *pcChain,
  [out]     PWSTR wszChain
);