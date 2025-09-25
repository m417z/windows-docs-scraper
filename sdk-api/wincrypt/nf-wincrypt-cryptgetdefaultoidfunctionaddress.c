BOOL CryptGetDefaultOIDFunctionAddress(
  [in]           HCRYPTOIDFUNCSET  hFuncSet,
  [in]           DWORD             dwEncodingType,
  [in, optional] LPCWSTR           pwszDll,
  [in]           DWORD             dwFlags,
  [out]          void              **ppvFuncAddr,
  [in, out]      HCRYPTOIDFUNCADDR *phFuncAddr
);