BOOL CryptImportKey(
  [in]  HCRYPTPROV hProv,
  [in]  const BYTE *pbData,
  [in]  DWORD      dwDataLen,
  [in]  HCRYPTKEY  hPubKey,
  [in]  DWORD      dwFlags,
  [out] HCRYPTKEY  *phKey
);