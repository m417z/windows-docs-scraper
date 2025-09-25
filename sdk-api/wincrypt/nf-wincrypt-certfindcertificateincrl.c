BOOL CertFindCertificateInCRL(
  [in]           PCCERT_CONTEXT pCert,
  [in]           PCCRL_CONTEXT  pCrlContext,
  [in]           DWORD          dwFlags,
  [in, optional] void           *pvReserved,
  [out]          PCRL_ENTRY     *ppCrlEntry
);