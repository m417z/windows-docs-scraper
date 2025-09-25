typedef struct _WNV_NOTIFICATION_PARAM {
  WNV_OBJECT_HEADER     Header;
  WNV_NOTIFICATION_TYPE NotificationType;
  ULONG                 PendingNotifications;
  PUCHAR                Buffer;
} WNV_NOTIFICATION_PARAM, *PWNV_NOTIFICATION_PARAM;