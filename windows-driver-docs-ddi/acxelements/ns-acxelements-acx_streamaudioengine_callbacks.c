typedef struct _ACX_STREAMAUDIOENGINE_CALLBACKS {
  ULONG                                                     Size;
  PFN_ACX_STREAMAUDIOENGINE_ASSIGN_EFFECTS_STATE            EvtAcxStreamAudioEngineAssignEffectsState;
  PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE          EvtAcxStreamAudioEngineRetrieveEffectsState;
  PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION  EvtAcxStreamAudioEngineRetrievePresentationPosition;
  PFN_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION   EvtAcxStreamAudioEngineAssignCurrentWritePosition;
  PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION EvtAcxStreamAudioEngineRetrieveLinearBufferPosition;
  PFN_ACX_STREAMAUDIOENGINE_ASSIGN_LAST_BUFFER_POSITION     EvtAcxStreamAudioEngineAssignLastBufferPosition;
  PFN_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION      EvtAcxStreamAudioEngineAssignLoopbackProtection;
  PFN_ACX_OBJECT_PROCESS_REQUEST                            EvtAcxStreamAudioEngineProcessRequest;
} ACX_STREAMAUDIOENGINE_CALLBACKS, *PACX_STREAMAUDIOENGINE_CALLBACKS;