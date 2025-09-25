CLFSUSER_API BOOL ValidateLog(
  [in]            LPCWSTR               pszLogFileName,
  [in, optional]  LPSECURITY_ATTRIBUTES psaLogFile,
  [out, optional] PCLFS_INFORMATION     pinfoBuffer,
  [in, out]       PULONG                pcbBuffer
);