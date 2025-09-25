typedef struct _WINHTTP_REQUEST_STATS {
  ULONGLONG ullFlags;
  ULONG     ulIndex;
  ULONG     cStats;
  ULONGLONG rgullStats[WinHttpRequestStatMax];
} WINHTTP_REQUEST_STATS, *PWINHTTP_REQUEST_STATS;