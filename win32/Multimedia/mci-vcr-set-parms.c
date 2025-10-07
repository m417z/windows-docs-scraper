typedef struct tagMCI_VCR_SET_PARMS {
  DWORD_PTR dwCallback;
  DWORD     dwTimeFormat;
  DWORD     dwAudio;
  DWORD     dwTimeMode;
  DWORD     dwRecordFormat;
  DWORD     dwCounterFormat;
  DWORD     dwIndex;
  DWORD     dwTracking;
  DWORD     dwSpeed;
  DWORD     dwLength;
  DWORD     dwCounter;
  DWORD     dwClock;
  DWORD     dwPauseTimeout;
  DWORD     dwPrerollDuration;
  DWORD     dwPostrollDuration;
} MCI_VCR_SET_PARMS;