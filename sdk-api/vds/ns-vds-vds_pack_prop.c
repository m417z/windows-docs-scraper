typedef struct _VDS_PACK_PROP {
  VDS_OBJECT_ID   id;
  LPWSTR          pwszName;
  VDS_PACK_STATUS status;
  ULONG           ulFlags;
} VDS_PACK_PROP, *PVDS_PACK_PROP;