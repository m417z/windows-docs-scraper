typedef struct _VDS_FILE_SYSTEM_TYPE_PROP {
  VDS_FILE_SYSTEM_TYPE type;
  WCHAR                wszName[8];
  ULONG                ulFlags;
  ULONG                ulCompressionFlags;
  ULONG                ulMaxLableLength;
  LPWSTR               pwszIllegalLabelCharSet;
} VDS_FILE_SYSTEM_TYPE_PROP, *PVDS_FILE_SYSTEM_TYPE_PROP;