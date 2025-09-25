typedef struct _VDS_FILE_SYSTEM_FORMAT_SUPPORT_PROP {
  ULONG  ulFlags;
  USHORT usRevision;
  ULONG  ulDefaultUnitAllocationSize;
  ULONG  rgulAllowedUnitAllocationSizes[32];
  WCHAR  wszName[32];
} VDS_FILE_SYSTEM_FORMAT_SUPPORT_PROP, *PVDS_FILE_SYSTEM_FORMAT_SUPPORT_PROP;