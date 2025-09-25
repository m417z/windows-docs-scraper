typedef struct TimeProvSysCallbacks {
  DWORD                 dwSize;
  GetTimeSysInfoFunc    *pfnGetTimeSysInfo;
  LogTimeProvEventFunc  *pfnLogTimeProvEvent;
  AlertSamplesAvailFunc *pfnAlertSamplesAvail;
  SetProviderStatusFunc *pfnSetProviderStatus;
} TimeProvSysCallbacks;