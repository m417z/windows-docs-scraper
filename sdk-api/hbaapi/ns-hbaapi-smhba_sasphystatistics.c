typedef struct SMHBA_SASPhyStatistics {
  HBA_INT64 SecondsSinceLastReset;
  HBA_INT64 TxFrames;
  HBA_INT64 TxWords;
  HBA_INT64 RxFrames;
  HBA_INT64 RxWords;
  HBA_INT64 InvalidDwordCount;
  HBA_INT64 RunningDisparityErrorCount;
  HBA_INT64 LossofDwordSyncCount;
  HBA_INT64 PhyResetProblemCount;
} SMHBA_SASPHYSTATISTICS, *PSMHBA_SASPHYSTATISTICS;