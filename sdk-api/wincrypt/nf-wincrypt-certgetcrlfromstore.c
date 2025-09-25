PCCRL_CONTEXT CertGetCRLFromStore(
  [in]           HCERTSTORE     hCertStore,
  [in, optional] PCCERT_CONTEXT pIssuerContext,
  [in]           PCCRL_CONTEXT  pPrevCrlContext,
  [in, out]      DWORD          *pdwFlags
);