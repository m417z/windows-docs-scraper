NTSTATUS PstGetCertificates(
  [in]           PUNICODE_STRING        pTargetName,
  [in]           DWORD                  cCriteria,
  [in, optional] PCCERT_SELECT_CRITERIA rgpCriteria,
  [in]           BOOL                   bIsClient,
  [out]          PDWORD                 pdwCertChainContextCount,
  [out]          PCCERT_CHAIN_CONTEXT   **ppCertChainContexts
);