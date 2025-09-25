BOOL CryptCATAdminCalcHashFromFileHandle(
  [in]      HANDLE hFile,
  [in, out] DWORD  *pcbHash,
  [in]      BYTE   *pbHash,
  [in]      DWORD  dwFlags
);