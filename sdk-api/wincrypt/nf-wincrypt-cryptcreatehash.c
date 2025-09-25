BOOL CryptCreateHash(
  [in]  HCRYPTPROV hProv,
  [in]  ALG_ID     Algid,
  [in]  HCRYPTKEY  hKey,
  [in]  DWORD      dwFlags,
  [out] HCRYPTHASH *phHash
);