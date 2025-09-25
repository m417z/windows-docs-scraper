typedef struct {
  KSDATARANGE DataRange;
  ULONG       MaximumChannels;
  ULONG       MinimumBitsPerSample;
  ULONG       MaximumBitsPerSample;
  ULONG       MinimumSampleFrequency;
  ULONG       MaximumSampleFrequency;
} KSDATARANGE_AUDIO, *PKSDATARANGE_AUDIO;