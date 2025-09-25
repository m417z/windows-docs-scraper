BOOL CertAddSerializedElementToStore(
  [in]  HCERTSTORE hCertStore,
  [in]  const BYTE *pbElement,
  [in]  DWORD      cbElement,
  [in]  DWORD      dwAddDisposition,
  [in]  DWORD      dwFlags,
  [in]  DWORD      dwContextTypeFlags,
  [out] DWORD      *pdwContextType,
  [out] const void **ppvContext
);