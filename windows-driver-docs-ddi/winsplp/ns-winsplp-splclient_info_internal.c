typedef struct _SPLCLIENT_INFO_INTERNAL {
  UINT   cbSize;
  DWORD  dwFlags;
  DWORD  dwSize;
  PWSTR  pMachineName;
  PWSTR  pUserName;
  DWORD  dwBuildNum;
  DWORD  dwMajorVersion;
  DWORD  dwMinorVersion;
  WORD   wProcessorArchitecture;
  UINT64 hSplPrinter;
  DWORD  dwProcessId;
  DWORD  dwSessionId;
} SPLCLIENT_INFO_INTERNAL;