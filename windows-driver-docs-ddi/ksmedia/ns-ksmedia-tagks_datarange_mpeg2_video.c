typedef struct tagKS_DATARANGE_MPEG2_VIDEO {
  KSDATARANGE                 DataRange;
  BOOL                        bFixedSizeSamples;
  BOOL                        bTemporalCompression;
  DWORD                       StreamDescriptionFlags;
  DWORD                       MemoryAllocationFlags;
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_MPEGVIDEOINFO2           VideoInfoHeader;
} KS_DATARANGE_MPEG2_VIDEO, *PKS_DATARANGE_MPEG2_VIDEO;