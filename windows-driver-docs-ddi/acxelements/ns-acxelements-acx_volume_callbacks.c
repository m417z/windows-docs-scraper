typedef struct _ACX_VOLUME_CALLBACKS {
  ULONG                              Size;
  PFN_ACX_VOLUME_ASSIGN_LEVEL        EvtAcxVolumeAssignLevel;
  PFN_ACX_RAMPED_VOLUME_ASSIGN_LEVEL EvtAcxRampedVolumeAssignLevel;
  PFN_ACX_VOLUME_RETRIEVE_LEVEL      EvtAcxVolumeRetrieveLevel;
  PFN_ACX_OBJECT_PROCESS_REQUEST     EvtAcxVolumeProcessRequest;
} ACX_VOLUME_CALLBACKS, *PACX_VOLUME_CALLBACKS;