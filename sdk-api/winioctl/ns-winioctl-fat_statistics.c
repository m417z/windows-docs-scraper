typedef struct _FAT_STATISTICS {
  DWORD CreateHits;
  DWORD SuccessfulCreates;
  DWORD FailedCreates;
  DWORD NonCachedReads;
  DWORD NonCachedReadBytes;
  DWORD NonCachedWrites;
  DWORD NonCachedWriteBytes;
  DWORD NonCachedDiskReads;
  DWORD NonCachedDiskWrites;
} FAT_STATISTICS, *PFAT_STATISTICS;