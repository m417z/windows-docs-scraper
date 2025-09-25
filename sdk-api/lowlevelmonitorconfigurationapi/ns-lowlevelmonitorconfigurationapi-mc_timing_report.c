typedef struct _MC_TIMING_REPORT {
  DWORD dwHorizontalFrequencyInHZ;
  DWORD dwVerticalFrequencyInHZ;
  BYTE  bTimingStatusByte;
} MC_TIMING_REPORT, *LPMC_TIMING_REPORT;