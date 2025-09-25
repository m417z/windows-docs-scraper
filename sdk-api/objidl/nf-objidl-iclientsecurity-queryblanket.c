HRESULT QueryBlanket(
  [in]  IUnknown *pProxy,
  [out] DWORD    *pAuthnSvc,
  [out] DWORD    *pAuthzSvc,
  [out] OLECHAR  **pServerPrincName,
  [out] DWORD    *pAuthnLevel,
  [out] DWORD    *pImpLevel,
  [out] void     **pAuthInfo,
  [out] DWORD    *pCapabilites
);