BOOL CertAddCRLContextToStore(
  [in]            HCERTSTORE    hCertStore,
  [in]            PCCRL_CONTEXT pCrlContext,
  [in]            DWORD         dwAddDisposition,
  [out, optional] PCCRL_CONTEXT *ppStoreContext
);