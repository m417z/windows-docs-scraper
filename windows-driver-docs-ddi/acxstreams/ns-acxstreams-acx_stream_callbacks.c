typedef struct _ACX_STREAM_CALLBACKS {
  ULONG                                Size;
  PFN_ACX_STREAM_PREPARE_HARDWARE      EvtAcxStreamPrepareHardware;
  PFN_ACX_STREAM_RELEASE_HARDWARE      EvtAcxStreamReleaseHardware;
  PFN_ACX_STREAM_RUN                   EvtAcxStreamRun;
  PFN_ACX_STREAM_PAUSE                 EvtAcxStreamPause;
  PFN_ACX_STREAM_ASSIGN_DRM_CONTENT_ID EvtAcxStreamAssignDrmContentId;
} ACX_STREAM_CALLBACKS, *PACX_STREAM_CALLBACKS;