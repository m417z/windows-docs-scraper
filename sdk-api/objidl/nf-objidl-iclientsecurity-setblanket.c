HRESULT SetBlanket(
  [in] IUnknown *pProxy,
  [in] DWORD    dwAuthnSvc,
  [in] DWORD    dwAuthzSvc,
  [in] OLECHAR  *pServerPrincName,
  [in] DWORD    dwAuthnLevel,
  [in] DWORD    dwImpLevel,
  [in] void     *pAuthInfo,
  [in] DWORD    dwCapabilities
);