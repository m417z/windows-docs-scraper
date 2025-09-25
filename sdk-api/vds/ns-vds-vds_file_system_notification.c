typedef struct _VDS_FILE_SYSTEM_NOTIFICATION {
  ULONG         ulEvent;
  VDS_OBJECT_ID volumeId;
  DWORD         dwPercentCompleted;
} VDS_FILE_SYSTEM_NOTIFICATION;