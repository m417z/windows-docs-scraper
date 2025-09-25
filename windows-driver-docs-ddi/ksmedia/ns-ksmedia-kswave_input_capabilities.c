typedef struct {
  ULONG MaximumChannelsPerConnection;
  ULONG MinimumBitsPerSample;
  ULONG MaximumBitsPerSample;
  ULONG MinimumSampleFrequency;
  ULONG MaximumSampleFrequency;
  ULONG TotalConnections;
  ULONG ActiveConnections;
} KSWAVE_INPUT_CAPABILITIES, *PKSWAVE_INPUT_CAPABILITIES;