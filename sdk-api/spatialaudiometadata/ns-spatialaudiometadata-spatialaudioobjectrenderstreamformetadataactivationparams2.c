typedef struct SpatialAudioObjectRenderStreamForMetadataActivationParams2 {
  const WAVEFORMATEX                    *ObjectFormat;
  AudioObjectType                       StaticObjectTypeMask;
  UINT32                                MinDynamicObjectCount;
  UINT32                                MaxDynamicObjectCount;
  AUDIO_STREAM_CATEGORY                 Category;
  HANDLE                                EventHandle;
  GUID                                  MetadataFormatId;
  UINT32                                MaxMetadataItemCount;
  const PROPVARIANT                     *MetadataActivationParams;
  ISpatialAudioObjectRenderStreamNotify *NotifyObject;
  SPATIAL_AUDIO_STREAM_OPTIONS          Options;
} SpatialAudioObjectRenderStreamForMetadataActivationParams2;