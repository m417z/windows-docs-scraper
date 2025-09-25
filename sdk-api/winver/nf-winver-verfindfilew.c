DWORD VerFindFileW(
  [in]           DWORD   uFlags,
  [in]           LPCWSTR szFileName,
  [in, optional] LPCWSTR szWinDir,
  [in]           LPCWSTR szAppDir,
  [out]          LPWSTR  szCurDir,
  [in, out]      PUINT   puCurDirLen,
  [out]          LPWSTR  szDestDir,
  [in, out]      PUINT   puDestDirLen
);