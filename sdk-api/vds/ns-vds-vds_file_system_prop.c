typedef struct _VDS_FILE_SYSTEM_PROP {
  VDS_FILE_SYSTEM_TYPE type;
  VDS_OBJECT_ID        volumeId;
  ULONG                ulFlags;
  ULONGLONG            ullTotalAllocationUnits;
  ULONGLONG            ullAvailableAllocationUnits;
  ULONG                ulAllocationUnitSize;
  LPWSTR               pwszLabel;
} VDS_FILE_SYSTEM_PROP, *PVDS_FILE_SYSTEM_PROP;