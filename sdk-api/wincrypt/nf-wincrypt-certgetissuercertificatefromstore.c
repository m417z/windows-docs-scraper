PCCERT_CONTEXT CertGetIssuerCertificateFromStore(
  [in]           HCERTSTORE     hCertStore,
  [in]           PCCERT_CONTEXT pSubjectContext,
  [in, optional] PCCERT_CONTEXT pPrevIssuerContext,
  [in, out]      DWORD          *pdwFlags
);