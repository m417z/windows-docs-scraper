DRMEXPORT HRESULT UDAPICALL DRMDeconstructCertificateChain(
  [in]      PWSTR wszChain,
  [in]      UINT  iWhich,
  [in, out] UINT  *pcCert,
  [out]     PWSTR wszCert
);