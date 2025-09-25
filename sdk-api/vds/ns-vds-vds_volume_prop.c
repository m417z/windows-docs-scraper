typedef struct _VDS_VOLUME_PROP {
  VDS_OBJECT_ID        id;
  VDS_VOLUME_TYPE      type;
  VDS_VOLUME_STATUS    status;
  VDS_HEALTH           health;
  VDS_TRANSITION_STATE TransitionState;
  ULONGLONG            ullSize;
  ULONG                ulFlags;
  VDS_FILE_SYSTEM_TYPE RecommendedFileSystemType;
  LPWSTR               pwszName;
} VDS_VOLUME_PROP, *PVDS_VOLUME_PROP;