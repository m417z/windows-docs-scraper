BOOL CryptGenKey(
  [in]  HCRYPTPROV hProv,
  [in]  ALG_ID     Algid,
  [in]  DWORD      dwFlags,
  [out] HCRYPTKEY  *phKey
);