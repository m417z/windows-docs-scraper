typedef struct _VDS_VOLUME_PLEX_PROP {
  VDS_OBJECT_ID          id;
  VDS_VOLUME_PLEX_TYPE   type;
  VDS_VOLUME_PLEX_STATUS status;
  VDS_HEALTH             health;
  VDS_TRANSITION_STATE   TransitionState;
  ULONGLONG              ullSize;
  ULONG                  ulStripeSize;
  ULONG                  ulNumberOfMembers;
} VDS_VOLUME_PLEX_PROP, *PVDS_VOLUME_PLEX_PROP;