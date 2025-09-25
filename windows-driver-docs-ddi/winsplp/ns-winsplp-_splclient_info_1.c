typedef struct _SPLCLIENT_INFO_1 {
  DWORD  dwSize;
  LPWSTR pMachineName;
  LPWSTR pUserName;
  DWORD  dwBuildNum;
  DWORD  dwMajorVersion;
  DWORD  dwMinorVersion;
  WORD   wProcessorArchitecture;
} SPLCLIENT_INFO_1, *PSPLCLIENT_INFO_1, *LPSPLCLIENT_INFO_1;