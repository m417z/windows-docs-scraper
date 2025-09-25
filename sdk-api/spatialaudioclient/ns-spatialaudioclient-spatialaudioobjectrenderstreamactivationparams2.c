typedef struct SpatialAudioObjectRenderStreamActivationParams2 {
  const WAVEFORMATEX                    *ObjectFormat;
  AudioObjectType                       StaticObjectTypeMask;
  UINT32                                MinDynamicObjectCount;
  UINT32                                MaxDynamicObjectCount;
  AUDIO_STREAM_CATEGORY                 Category;
  HANDLE                                EventHandle;
  ISpatialAudioObjectRenderStreamNotify *NotifyObject;
  SPATIAL_AUDIO_STREAM_OPTIONS          Options;
} SpatialAudioObjectRenderStreamActivationParams2;