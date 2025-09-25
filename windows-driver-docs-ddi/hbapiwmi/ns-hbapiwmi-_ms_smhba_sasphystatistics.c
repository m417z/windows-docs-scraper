typedef struct _MS_SMHBA_SASPHYSTATISTICS {
  LONGLONG SecondsSinceLastReset;
  LONGLONG TxFrames;
  LONGLONG TxWords;
  LONGLONG RxFrames;
  LONGLONG RxWords;
  LONGLONG InvalidDwordCount;
  LONGLONG RunningDisparityErrorCount;
  LONGLONG LossofDwordSyncCount;
  LONGLONG PhyResetProblemCount;
} MS_SMHBA_SASPHYSTATISTICS, *PMS_SMHBA_SASPHYSTATISTICS;