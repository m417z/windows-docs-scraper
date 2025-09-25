BOOL CryptExportKey(
  [in]      HCRYPTKEY hKey,
  [in]      HCRYPTKEY hExpKey,
  [in]      DWORD     dwBlobType,
  [in]      DWORD     dwFlags,
  [out]     BYTE      *pbData,
  [in, out] DWORD     *pdwDataLen
);