typedef struct tagKS_DATARANGE_VIDEO_PALETTE {
  KSDATARANGE                 DataRange;
  BOOL                        bFixedSizeSamples;
  BOOL                        bTemporalCompression;
  DWORD                       StreamDescriptionFlags;
  DWORD                       MemoryAllocationFlags;
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_VIDEOINFO                VideoInfo;
} KS_DATARANGE_VIDEO_PALETTE, *PKS_DATARANGE_VIDEO_PALETTE;