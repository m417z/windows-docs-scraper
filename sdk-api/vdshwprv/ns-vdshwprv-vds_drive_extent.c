typedef struct _VDS_DRIVE_EXTENT {
  VDS_OBJECT_ID id;
  VDS_OBJECT_ID LunId;
  ULONGLONG     ullSize;
  BOOL          bUsed;
} VDS_DRIVE_EXTENT, *PVDS_DRIVE_EXTENT;