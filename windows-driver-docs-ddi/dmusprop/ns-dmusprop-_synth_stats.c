typedef struct _SYNTH_STATS {
  DWORD ValidStats;
  DWORD Voices;
  DWORD TotalCPU;
  DWORD CPUPerVoice;
  DWORD LostNotes;
  DWORD FreeMemory;
  LONG  PeakVolume;
} SYNTH_STATS, *PSYNTH_STATS;