BOOL CertVerifySubjectCertificateContext(
  [in]           PCCERT_CONTEXT pSubject,
  [in, optional] PCCERT_CONTEXT pIssuer,
  [in, out]      DWORD          *pdwFlags
);