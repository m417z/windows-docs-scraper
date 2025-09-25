typedef struct _EXFAT_STATISTICS {
  DWORD CreateHits;
  DWORD SuccessfulCreates;
  DWORD FailedCreates;
  DWORD NonCachedReads;
  DWORD NonCachedReadBytes;
  DWORD NonCachedWrites;
  DWORD NonCachedWriteBytes;
  DWORD NonCachedDiskReads;
  DWORD NonCachedDiskWrites;
} EXFAT_STATISTICS, *PEXFAT_STATISTICS;