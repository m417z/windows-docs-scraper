typedef struct _VDS_LUN_PROP {
  VDS_OBJECT_ID        id;
  ULONGLONG            ullSize;
  LPWSTR               pwszFriendlyName;
  LPWSTR               pwszIdentification;
  LPWSTR               pwszUnmaskingList;
  ULONG                ulFlags;
  VDS_LUN_TYPE         type;
  VDS_LUN_STATUS       status;
  VDS_HEALTH           health;
  VDS_TRANSITION_STATE TransitionState;
  SHORT                sRebuildPriority;
} VDS_LUN_PROP, *PVDS_LUN_PROP;