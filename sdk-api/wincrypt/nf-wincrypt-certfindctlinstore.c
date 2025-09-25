PCCTL_CONTEXT CertFindCTLInStore(
  [in] HCERTSTORE    hCertStore,
  [in] DWORD         dwMsgAndCertEncodingType,
  [in] DWORD         dwFindFlags,
  [in] DWORD         dwFindType,
  [in] const void    *pvFindPara,
  [in] PCCTL_CONTEXT pPrevCtlContext
);