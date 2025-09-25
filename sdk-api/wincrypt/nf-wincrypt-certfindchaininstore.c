PCCERT_CHAIN_CONTEXT CertFindChainInStore(
  [in] HCERTSTORE           hCertStore,
  [in] DWORD                dwCertEncodingType,
  [in] DWORD                dwFindFlags,
  [in] DWORD                dwFindType,
  [in] const void           *pvFindPara,
  [in] PCCERT_CHAIN_CONTEXT pPrevChainContext
);