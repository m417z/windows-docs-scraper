typedef struct _VDS_PATH_POLICY {
  VDS_PATH_ID pathId;
  BOOL        bPrimaryPath;
  ULONG       ulWeight;
} VDS_PATH_POLICY;