DWORD VerInstallFileW(
  [in]      DWORD   uFlags,
  [in]      LPCWSTR szSrcFileName,
  [in]      LPCWSTR szDestFileName,
  [in]      LPCWSTR szSrcDir,
  [in]      LPCWSTR szDestDir,
  [in]      LPCWSTR szCurDir,
  [out]     LPWSTR  szTmpFile,
  [in, out] PUINT   puTmpFileLen
);