DWORD VerInstallFileA(
  [in]      DWORD  uFlags,
  [in]      LPCSTR szSrcFileName,
  [in]      LPCSTR szDestFileName,
  [in]      LPCSTR szSrcDir,
  [in]      LPCSTR szDestDir,
  [in]      LPCSTR szCurDir,
  [out]     LPSTR  szTmpFile,
  [in, out] PUINT  puTmpFileLen
);