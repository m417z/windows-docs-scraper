typedef struct _VDS_VOLUME_NOTIFICATION {
  ULONG         ulEvent;
  VDS_OBJECT_ID volumeId;
  VDS_OBJECT_ID plexId;
  ULONG         ulPercentCompleted;
} VDS_VOLUME_NOTIFICATION;