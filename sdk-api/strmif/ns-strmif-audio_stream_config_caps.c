typedef struct _AUDIO_STREAM_CONFIG_CAPS {
  GUID  guid;
  ULONG MinimumChannels;
  ULONG MaximumChannels;
  ULONG ChannelsGranularity;
  ULONG MinimumBitsPerSample;
  ULONG MaximumBitsPerSample;
  ULONG BitsPerSampleGranularity;
  ULONG MinimumSampleFrequency;
  ULONG MaximumSampleFrequency;
  ULONG SampleFrequencyGranularity;
} AUDIO_STREAM_CONFIG_CAPS;