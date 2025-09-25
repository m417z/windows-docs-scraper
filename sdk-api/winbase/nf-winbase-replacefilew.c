BOOL ReplaceFileW(
  [in]           LPCWSTR lpReplacedFileName,
  [in]           LPCWSTR lpReplacementFileName,
  [in, optional] LPCWSTR lpBackupFileName,
  [in]           DWORD   dwReplaceFlags,
                 LPVOID  lpExclude,
                 LPVOID  lpReserved
);