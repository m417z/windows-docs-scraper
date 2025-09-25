typedef struct _QUERY_ON_CREATE_FILE_LX_INFORMATION {
  ACCESS_MASK EffectiveAccess;
  ULONG       LxFlags;
  ULONG       LxUid;
  ULONG       LxGid;
  ULONG       LxMode;
  ULONG       LxDeviceIdMajor;
  ULONG       LxDeviceIdMinor;
} QUERY_ON_CREATE_FILE_LX_INFORMATION, *PQUERY_ON_CREATE_FILE_LX_INFORMATION;