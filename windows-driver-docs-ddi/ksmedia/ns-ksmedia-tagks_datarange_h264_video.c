typedef struct tagKS_DATARANGE_H264_VIDEO {
  KSDATARANGE                 DataRange;
  BOOL                        bFixedSizeSamples;
  BOOL                        bTemporalCompression;
  DWORD                       StreamDescriptionFlags;
  DWORD                       MemoryAllocationFlags;
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_H264VIDEOINFO            VideoInfoHeader;
} KS_DATARANGE_H264_VIDEO, *PKS_DATARANGE_H264_VIDEO;