BOOL CertGetCertificateContextProperty(
  [in]      PCCERT_CONTEXT pCertContext,
  [in]      DWORD          dwPropId,
  [out]     void           *pvData,
  [in, out] DWORD          *pcbData
);