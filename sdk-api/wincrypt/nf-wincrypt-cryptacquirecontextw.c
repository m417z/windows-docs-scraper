BOOL CryptAcquireContextW(
  [out] HCRYPTPROV *phProv,
  [in]  LPCWSTR    szContainer,
  [in]  LPCWSTR    szProvider,
  [in]  DWORD      dwProvType,
  [in]  DWORD      dwFlags
);