PCCERT_CONTEXT CertFindCertificateInStore(
  [in] HCERTSTORE     hCertStore,
  [in] DWORD          dwCertEncodingType,
  [in] DWORD          dwFindFlags,
  [in] DWORD          dwFindType,
  [in] const void     *pvFindPara,
  [in] PCCERT_CONTEXT pPrevCertContext
);