BOOL CryptGetKeyParam(
  [in]      HCRYPTKEY hKey,
  [in]      DWORD     dwParam,
  [out]     BYTE      *pbData,
  [in, out] DWORD     *pdwDataLen,
  [in]      DWORD     dwFlags
);