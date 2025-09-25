BOOL CryptGetProvParam(
  [in]      HCRYPTPROV hProv,
  [in]      DWORD      dwParam,
  [out]     BYTE       *pbData,
  [in, out] DWORD      *pdwDataLen,
  [in]      DWORD      dwFlags
);