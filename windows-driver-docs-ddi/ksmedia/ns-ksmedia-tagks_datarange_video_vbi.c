typedef struct tagKS_DATARANGE_VIDEO_VBI {
  KSDATARANGE                 DataRange;
  BOOL                        bFixedSizeSamples;
  BOOL                        bTemporalCompression;
  DWORD                       StreamDescriptionFlags;
  DWORD                       MemoryAllocationFlags;
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_VBIINFOHEADER            VBIInfoHeader;
} KS_DATARANGE_VIDEO_VBI, *PKS_DATARANGE_VIDEO_VBI;