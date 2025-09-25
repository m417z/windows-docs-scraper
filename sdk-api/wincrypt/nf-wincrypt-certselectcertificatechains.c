BOOL CertSelectCertificateChains(
  [in, optional] LPCGUID                  pSelectionContext,
  [in]           DWORD                    dwFlags,
  [in, optional] PCCERT_SELECT_CHAIN_PARA pChainParameters,
  [in]           DWORD                    cCriteria,
  [in, optional] PCCERT_SELECT_CRITERIA   rgpCriteria,
  [in]           HCERTSTORE               hStore,
  [out]          PDWORD                   pcSelection,
  [out]          PCCERT_CHAIN_CONTEXT     **pprgpSelection
);