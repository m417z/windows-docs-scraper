typedef struct _PDH_STATISTICS {
  DWORD                dwFormat;
  DWORD                count;
  PDH_FMT_COUNTERVALUE min;
  PDH_FMT_COUNTERVALUE max;
  PDH_FMT_COUNTERVALUE mean;
} PDH_STATISTICS, *PPDH_STATISTICS;