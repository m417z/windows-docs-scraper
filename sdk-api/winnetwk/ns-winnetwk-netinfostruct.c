typedef struct _NETINFOSTRUCT {
  DWORD     cbStructure;
  DWORD     dwProviderVersion;
  DWORD     dwStatus;
  DWORD     dwCharacteristics;
  ULONG_PTR dwHandle;
  WORD      wNetType;
  DWORD     dwPrinters;
  DWORD     dwDrives;
} NETINFOSTRUCT, *LPNETINFOSTRUCT;