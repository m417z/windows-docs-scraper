typedef struct _SPLCLIENT_INFO_3_VISTA {
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
} SPLCLIENT_INFO_3_VISTA;