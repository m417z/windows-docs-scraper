typedef struct _VDS_LUN_PLEX_PROP {
  VDS_OBJECT_ID        id;
  ULONGLONG            ullSize;
  VDS_LUN_PLEX_TYPE    type;
  VDS_LUN_PLEX_STATUS  status;
  VDS_HEALTH           health;
  VDS_TRANSITION_STATE TransitionState;
  ULONG                ulFlags;
  ULONG                ulStripeSize;
  SHORT                sRebuildPriority;
} VDS_LUN_PLEX_PROP, *PVDS_LUN_PLEX_PROP;