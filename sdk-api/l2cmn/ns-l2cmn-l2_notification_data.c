typedef struct _L2_NOTIFICATION_DATA {
  DWORD NotificationSource;
  DWORD NotificationCode;
  GUID  InterfaceGuid;
  DWORD dwDataSize;
#if ...
  PBYTE pData;
#else
  PVOID pData;
#endif
} L2_NOTIFICATION_DATA, *PL2_NOTIFICATION_DATA;