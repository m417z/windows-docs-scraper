typedef struct tagKS_DATARANGE_MPEG1_VIDEO {
  KSDATARANGE                 DataRange;
  BOOL                        bFixedSizeSamples;
  BOOL                        bTemporalCompression;
  DWORD                       StreamDescriptionFlags;
  DWORD                       MemoryAllocationFlags;
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_MPEG1VIDEOINFO           VideoInfoHeader;
} KS_DATARANGE_MPEG1_VIDEO, *PKS_DATARANGE_MPEG1_VIDEO;