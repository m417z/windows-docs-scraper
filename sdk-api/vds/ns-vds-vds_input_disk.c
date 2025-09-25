typedef struct _VDS_INPUT_DISK {
  VDS_OBJECT_ID diskId;
  ULONGLONG     ullSize;
  VDS_OBJECT_ID plexId;
  ULONG         memberIdx;
} VDS_INPUT_DISK;