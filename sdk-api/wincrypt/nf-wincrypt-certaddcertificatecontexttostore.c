BOOL CertAddCertificateContextToStore(
  [in]            HCERTSTORE     hCertStore,
  [in]            PCCERT_CONTEXT pCertContext,
  [in]            DWORD          dwAddDisposition,
  [out, optional] PCCERT_CONTEXT *ppStoreContext
);