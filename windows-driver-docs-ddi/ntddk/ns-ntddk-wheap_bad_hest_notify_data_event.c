typedef struct _WHEAP_BAD_HEST_NOTIFY_DATA_EVENT {
  WHEA_EVENT_LOG_ENTRY         WheaEventLogEntry;
  USHORT                       SourceId;
  USHORT                       Reserved;
  WHEA_NOTIFICATION_DESCRIPTOR NotifyDesc;
} WHEAP_BAD_HEST_NOTIFY_DATA_EVENT, *PWHEAP_BAD_HEST_NOTIFY_DATA_EVENT;