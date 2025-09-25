BOOL ReplaceFileA(
  [in]           LPCSTR lpReplacedFileName,
  [in]           LPCSTR lpReplacementFileName,
  [in, optional] LPCSTR lpBackupFileName,
  [in]           DWORD  dwReplaceFlags,
                 LPVOID lpExclude,
                 LPVOID lpReserved
);