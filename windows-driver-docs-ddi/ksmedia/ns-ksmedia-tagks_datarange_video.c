typedef struct tagKS_DATARANGE_VIDEO {
  KSDATARANGE                 DataRange;
  BOOL                        bFixedSizeSamples;
  BOOL                        bTemporalCompression;
  DWORD                       StreamDescriptionFlags;
  DWORD                       MemoryAllocationFlags;
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_VIDEOINFOHEADER          VideoInfoHeader;
} KS_DATARANGE_VIDEO, *PKS_DATARANGE_VIDEO;