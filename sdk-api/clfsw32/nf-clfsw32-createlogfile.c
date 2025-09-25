CLFSUSER_API HANDLE CreateLogFile(
  [in]           LPCWSTR               pszLogFileName,
  [in]           ACCESS_MASK           fDesiredAccess,
  [in]           DWORD                 dwShareMode,
  [in, optional] LPSECURITY_ATTRIBUTES psaLogFile,
  [in]           ULONG                 fCreateDisposition,
  [in]           ULONG                 fFlagsAndAttributes
);