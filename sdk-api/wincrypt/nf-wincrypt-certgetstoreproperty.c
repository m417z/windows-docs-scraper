BOOL CertGetStoreProperty(
  [in]      HCERTSTORE hCertStore,
  [in]      DWORD      dwPropId,
  [out]     void       *pvData,
  [in, out] DWORD      *pcbData
);