BOOL CertGetCertificateChain(
  [in, optional] HCERTCHAINENGINE     hChainEngine,
  [in]           PCCERT_CONTEXT       pCertContext,
  [in, optional] LPFILETIME           pTime,
  [in]           HCERTSTORE           hAdditionalStore,
  [in]           PCERT_CHAIN_PARA     pChainPara,
  [in]           DWORD                dwFlags,
  [in]           LPVOID               pvReserved,
  [out]          PCCERT_CHAIN_CONTEXT *ppChainContext
);