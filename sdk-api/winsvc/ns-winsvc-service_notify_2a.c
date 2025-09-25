typedef struct _SERVICE_NOTIFY_2A {
  DWORD                  dwVersion;
  PFN_SC_NOTIFY_CALLBACK pfnNotifyCallback;
  PVOID                  pContext;
  DWORD                  dwNotificationStatus;
  SERVICE_STATUS_PROCESS ServiceStatus;
  DWORD                  dwNotificationTriggered;
  LPSTR                  pszServiceNames;
} SERVICE_NOTIFY_2A, *PSERVICE_NOTIFY_2A;