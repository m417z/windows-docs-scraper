typedef struct XAUDIO2_PERFORMANCE_DATA {
  UINT64 AudioCyclesSinceLastQuery;
  UINT64 TotalCyclesSinceLastQuery;
  UINT32 MinimumCyclesPerQuantum;
  UINT32 MaximumCyclesPerQuantum;
  UINT32 MemoryUsageInBytes;
  UINT32 CurrentLatencyInSamples;
  UINT32 GlitchesSinceEngineStarted;
  UINT32 ActiveSourceVoiceCount;
  UINT32 TotalSourceVoiceCount;
  UINT32 ActiveSubmixVoiceCount;
  UINT32 ActiveResamplerCount;
  UINT32 ActiveMatrixMixCount;
  UINT32 ActiveXmaSourceVoices;
  UINT32 ActiveXmaStreams;
} XAUDIO2_PERFORMANCE_DATA;