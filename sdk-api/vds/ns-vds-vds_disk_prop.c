typedef struct _VDS_DISK_PROP {
  VDS_OBJECT_ID        id;
  VDS_DISK_STATUS      status;
  VDS_LUN_RESERVE_MODE ReserveMode;
  VDS_HEALTH           health;
  DWORD                dwDeviceType;
  DWORD                dwMediaType;
  ULONGLONG            ullSize;
  ULONG                ulBytesPerSector;
  ULONG                ulSectorsPerTrack;
  ULONG                ulTracksPerCylinder;
  ULONG                ulFlags;
  VDS_STORAGE_BUS_TYPE BusType;
  VDS_PARTITION_STYLE  PartitionStyle;
  union {
    DWORD dwSignature;
    GUID  DiskGuid;
  };
  LPWSTR               pwszDiskAddress;
  LPWSTR               pwszName;
  LPWSTR               pwszFriendlyName;
  LPWSTR               pwszAdaptorName;
  LPWSTR               pwszDevicePath;
} VDS_DISK_PROP, *PVDS_DISK_PROP;