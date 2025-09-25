BOOL CryptGetOIDFunctionAddress(
  [in]  HCRYPTOIDFUNCSET  hFuncSet,
  [in]  DWORD             dwEncodingType,
  [in]  LPCSTR            pszOID,
  [in]  DWORD             dwFlags,
  [out] void              **ppvFuncAddr,
  [out] HCRYPTOIDFUNCADDR *phFuncAddr
);