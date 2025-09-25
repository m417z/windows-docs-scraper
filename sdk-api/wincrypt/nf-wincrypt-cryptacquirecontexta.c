BOOL CryptAcquireContextA(
  [out] HCRYPTPROV *phProv,
  [in]  LPCSTR     szContainer,
  [in]  LPCSTR     szProvider,
  [in]  DWORD      dwProvType,
  [in]  DWORD      dwFlags
);