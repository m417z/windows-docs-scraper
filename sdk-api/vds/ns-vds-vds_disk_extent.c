typedef struct _VDS_DISK_EXTENT {
  VDS_OBJECT_ID        diskId;
  VDS_DISK_EXTENT_TYPE type;
  ULONGLONG            ullOffset;
  ULONGLONG            ullSize;
  VDS_OBJECT_ID        volumeId;
  VDS_OBJECT_ID        plexId;
  ULONG                memberIdx;
} VDS_DISK_EXTENT, *PVDS_DISK_EXTENT;