typedef enum WICProgressNotification {
  WICProgressNotificationBegin = 0x10000,
  WICProgressNotificationEnd = 0x20000,
  WICProgressNotificationFrequent = 0x40000,
  WICProgressNotificationAll = 0xffff0000,
  WICPROGRESSNOTIFICATION_FORCE_DWORD = 0x7fffffff
} ;