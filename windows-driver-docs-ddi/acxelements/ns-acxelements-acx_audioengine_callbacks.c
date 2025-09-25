typedef struct _ACX_AUDIOENGINE_CALLBACKS {
  ULONG                                           Size;
  PFN_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS EvtAcxAudioEngineRetrieveBufferSizeLimits;
  PFN_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE        EvtAcxAudioEngineAssignEffectsState;
  PFN_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE      EvtAcxAudioEngineRetrieveEffectsState;
  PFN_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT      EvtAcxAudioEngineRetrieveEngineMixFormat;
  PFN_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT        EvtAcxAudioEngineAssignEngineDeviceFormat;
  PFN_ACX_OBJECT_PROCESS_REQUEST                  EvtAcxAudioEngineProcessRequest;
} ACX_AUDIOENGINE_CALLBACKS, *PACX_AUDIOENGINE_CALLBACKS;