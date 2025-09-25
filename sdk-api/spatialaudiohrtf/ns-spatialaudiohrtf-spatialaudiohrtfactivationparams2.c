typedef struct SpatialAudioHrtfActivationParams2 {
  const WAVEFORMATEX                    *ObjectFormat;
  AudioObjectType                       StaticObjectTypeMask;
  UINT32                                MinDynamicObjectCount;
  UINT32                                MaxDynamicObjectCount;
  AUDIO_STREAM_CATEGORY                 Category;
  HANDLE                                EventHandle;
  ISpatialAudioObjectRenderStreamNotify *NotifyObject;
  SpatialAudioHrtfDistanceDecay         *DistanceDecay;
  SpatialAudioHrtfDirectivityUnion      *Directivity;
  SpatialAudioHrtfEnvironmentType       *Environment;
  SpatialAudioHrtfOrientation           *Orientation;
  SPATIAL_AUDIO_STREAM_OPTIONS          Options;
} SpatialAudioHrtfActivationParams2;