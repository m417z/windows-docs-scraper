typedef struct SpatialAudioObjectRenderStreamForMetadataActivationParams {
  const WAVEFORMATEX                    *ObjectFormat;
  AudioObjectType                       StaticObjectTypeMask;
  UINT32                                MinDynamicObjectCount;
  UINT32                                MaxDynamicObjectCount;
  AUDIO_STREAM_CATEGORY                 Category;
  HANDLE                                EventHandle;
  GUID                                  MetadataFormatId;
  UINT16                                MaxMetadataItemCount;
  const PROPVARIANT                     *MetadataActivationParams;
  ISpatialAudioObjectRenderStreamNotify *NotifyObject;
} SpatialAudioObjectRenderStreamForMetadataActivationParams;