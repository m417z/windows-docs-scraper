BOOL CertAddCTLLinkToStore(
  [in]            HCERTSTORE    hCertStore,
  [in]            PCCTL_CONTEXT pCtlContext,
  [in]            DWORD         dwAddDisposition,
  [out, optional] PCCTL_CONTEXT *ppStoreContext
);