typedef struct tagKS_DATARANGE_VIDEO2 {
  KSDATARANGE                 DataRange;
  BOOL                        bFixedSizeSamples;
  BOOL                        bTemporalCompression;
  DWORD                       StreamDescriptionFlags;
  DWORD                       MemoryAllocationFlags;
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_VIDEOINFOHEADER2         VideoInfoHeader;
} KS_DATARANGE_VIDEO2, *PKS_DATARANGE_VIDEO2;