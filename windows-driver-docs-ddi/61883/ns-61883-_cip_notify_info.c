typedef struct _CIP_NOTIFY_INFO {
  HANDLE     hConnect;
  PVOID      Context;
  PCIP_FRAME Frame;
} CIP_NOTIFY_INFO, *PCIP_NOTIFY_INFO;