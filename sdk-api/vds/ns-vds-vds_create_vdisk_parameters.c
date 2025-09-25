typedef struct _VDS_CREATE_VDISK_PARAMETERS {
  GUID      UniqueId;
  ULONGLONG MaximumSize;
  ULONG     BlockSizeInBytes;
  ULONG     SectorSizeInBytes;
  LPWSTR    pParentPath;
  LPWSTR    pSourcePath;
} VDS_CREATE_VDISK_PARAMETERS, *PVDS_CREATE_VDISK_PARAMETERS;