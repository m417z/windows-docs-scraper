typedef struct _PS_DRRSEQ_STATS {
  ULONG MaxPacketsInNetcard;
  ULONG AveragePacketsInNetcard;
  ULONG MaxPacketsInSequencer;
  ULONG AveragePacketsInSequencer;
  ULONG NonconformingPacketsTransmitted;
} PS_DRRSEQ_STATS, *PPS_DRRSEQ_STATS;