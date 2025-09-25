typedef struct {
  UINT64 TotalCycleCount;
  UINT64 TotalWallClockPeriod;
  UINT64 VaCloneCycleCount;
  UINT64 VaCloneWallClockPeriod;
  UINT64 VaSpaceCycleCount;
  UINT64 VaSpaceWallClockPeriod;
  UINT64 AuxPagesCycleCount;
  UINT64 AuxPagesWallClockPeriod;
  UINT64 HandlesCycleCount;
  UINT64 HandlesWallClockPeriod;
  UINT64 ThreadsCycleCount;
  UINT64 ThreadsWallClockPeriod;
} PSS_PERFORMANCE_COUNTERS;