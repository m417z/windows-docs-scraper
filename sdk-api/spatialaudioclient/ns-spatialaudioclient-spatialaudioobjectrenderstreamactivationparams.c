typedef struct SpatialAudioObjectRenderStreamActivationParams {
  const WAVEFORMATEX                    *ObjectFormat;
  AudioObjectType                       StaticObjectTypeMask;
  UINT32                                MinDynamicObjectCount;
  UINT32                                MaxDynamicObjectCount;
  AUDIO_STREAM_CATEGORY                 Category;
  HANDLE                                EventHandle;
  ISpatialAudioObjectRenderStreamNotify *NotifyObject;
} SpatialAudioObjectRenderStreamActivationParams;