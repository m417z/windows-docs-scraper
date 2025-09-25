typedef struct _NOTIFICATION_CONFIG_1 {
  UINT                   cbSize;
  DWORD                  fdwFlags;
  ROUTER_NOTIFY_CALLBACK pfnNotifyCallback;
  PVOID                  pContext;
} NOTIFICATION_CONFIG_1, *PNOTIFICATION_CONFIG_1;