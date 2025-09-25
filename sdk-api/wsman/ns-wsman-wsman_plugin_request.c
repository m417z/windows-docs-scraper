typedef struct _WSMAN_PLUGIN_REQUEST {
  WSMAN_SENDER_DETAILS *senderDetails;
  PCWSTR               locale;
  PCWSTR               resourceUri;
  WSMAN_OPERATION_INFO *operationInfo;
  BOOL                 shutdownNotification;
  HANDLE               shutdownNotificationHandle;
  PCWSTR               dataLocale;
} WSMAN_PLUGIN_REQUEST;