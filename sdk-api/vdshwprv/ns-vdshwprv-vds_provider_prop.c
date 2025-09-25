typedef struct _VDS_PROVIDER_PROP {
  VDS_OBJECT_ID     id;
  LPWSTR            pwszName;
  GUID              guidVersionId;
  LPWSTR            pwszVersion;
  VDS_PROVIDER_TYPE type;
  ULONG             ulFlags;
  ULONG             ulStripeSizeFlags;
  SHORT             sRebuildPriority;
} VDS_PROVIDER_PROP;