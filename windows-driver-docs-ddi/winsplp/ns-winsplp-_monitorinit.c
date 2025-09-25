typedef struct _MONITORINIT {
  DWORD       cbSize;
  HANDLE      hSpooler;
  HKEYMONITOR hckRegistryRoot;
  PMONITORREG pMonitorReg;
  BOOL        bLocal;
  LPCWSTR     pszServerName;
} MONITORINIT, *PMONITORINIT;