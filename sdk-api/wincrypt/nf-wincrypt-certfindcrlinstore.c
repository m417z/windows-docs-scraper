PCCRL_CONTEXT CertFindCRLInStore(
  [in] HCERTSTORE    hCertStore,
  [in] DWORD         dwCertEncodingType,
  [in] DWORD         dwFindFlags,
  [in] DWORD         dwFindType,
  [in] const void    *pvFindPara,
  [in] PCCRL_CONTEXT pPrevCrlContext
);