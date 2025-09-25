typedef struct _STINOTIFY {
  DWORD dwSize;
  GUID  guidNotificationCode;
  BYTE  abNotificationData[MAX_NOTIFICATION_DATA];
} STINOTIFY, *LPSTINOTIFY;