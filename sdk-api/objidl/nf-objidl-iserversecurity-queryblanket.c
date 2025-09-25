HRESULT QueryBlanket(
  [out]     DWORD   *pAuthnSvc,
  [out]     DWORD   *pAuthzSvc,
  [out]     OLECHAR **pServerPrincName,
  [out]     DWORD   *pAuthnLevel,
  [out]     DWORD   *pImpLevel,
  [out]     void    **pPrivs,
  [in, out] DWORD   *pCapabilities
);