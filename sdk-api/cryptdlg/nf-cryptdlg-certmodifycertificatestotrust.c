CRYPTDLGAPI HRESULT CertModifyCertificatesToTrust(
  [in]           int                 cCerts,
  [in]           PCTL_MODIFY_REQUEST rgCerts,
  [in]           LPCSTR              szPurpose,
  [in]           HWND                hwnd,
  [in, optional] HCERTSTORE          hcertstoreTrust,
  [in, optional] PCCERT_CONTEXT      pccertSigner
);