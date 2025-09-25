typedef struct _VDS_VOLUME_PROP2 {
  VDS_OBJECT_ID        id;
  VDS_VOLUME_TYPE      type;
  VDS_VOLUME_STATUS    status;
  VDS_HEALTH           health;
  VDS_TRANSITION_STATE TransitionState;
  ULONGLONG            ullSize;
  ULONG                ulFlags;
  VDS_FILE_SYSTEM_TYPE RecommendedFileSystemType;
  ULONG                cbUniqueId;
  LPWSTR               pwszName;
  BYTE                 *pUniqueId;
} VDS_VOLUME_PROP2, *PVDS_VOLUME_PROP2;