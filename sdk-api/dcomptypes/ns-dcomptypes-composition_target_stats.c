typedef struct tagCOMPOSITION_TARGET_STATS {
  UINT              outstandingPresents;
  UINT64            presentTime;
  UINT64            vblankDuration;
  COMPOSITION_STATS presentedStats;
  COMPOSITION_STATS completedStats;
} COMPOSITION_TARGET_STATS;