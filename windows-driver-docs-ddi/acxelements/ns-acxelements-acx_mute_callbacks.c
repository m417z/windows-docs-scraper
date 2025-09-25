typedef struct _ACX_MUTE_CALLBACKS {
  ULONG                          Size;
  PFN_ACX_MUTE_ASSIGN_STATE      EvtAcxMuteAssignState;
  PFN_ACX_MUTE_RETRIEVE_STATE    EvtAcxMuteRetrieveState;
  PFN_ACX_OBJECT_PROCESS_REQUEST EvtAcxMuteProcessRequest;
} ACX_MUTE_CALLBACKS, *PACX_MUTE_CALLBACKS;