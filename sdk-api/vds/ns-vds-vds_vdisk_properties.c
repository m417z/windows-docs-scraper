typedef struct _VDS_VDISK_PROPERTIES {
  VDS_OBJECT_ID        Id;
  VDS_VDISK_STATE      State;
  VIRTUAL_STORAGE_TYPE VirtualDeviceType;
  ULONGLONG            VirtualSize;
  ULONGLONG            PhysicalSize;
  LPWSTR               pPath;
  LPWSTR               pDeviceName;
  DEPENDENT_DISK_FLAG  DiskFlag;
  BOOL                 bIsChild;
  LPWSTR               pParentPath;
} VDS_VDISK_PROPERTIES, *PVDS_VDISK_PROPERTIES;