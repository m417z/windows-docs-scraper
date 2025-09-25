typedef struct _SERVICE_NOTIFY_2W {
  DWORD                  dwVersion;
  PFN_SC_NOTIFY_CALLBACK pfnNotifyCallback;
  PVOID                  pContext;
  DWORD                  dwNotificationStatus;
  SERVICE_STATUS_PROCESS ServiceStatus;
  DWORD                  dwNotificationTriggered;
  LPWSTR                 pszServiceNames;
} SERVICE_NOTIFY_2W, *PSERVICE_NOTIFY_2W;