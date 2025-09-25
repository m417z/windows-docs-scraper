DWORD GenerateCopyFilePaths(
  [in]      LPCWSTR pszPrinterName,
  [in]      LPCWSTR pszDirectory,
  [in]      LPBYTE  pSplClientInfo,
  [in]      DWORD   dwLevel,
  [in, out] LPWSTR  pszSourceDir,
  [in, out] LPDWORD pcchSourceDirSize,
  [in, out] LPWSTR  pszTargetDir,
  [in, out] LPDWORD pcchTargetDirSize,
  [in]      DWORD   dwFlags
);