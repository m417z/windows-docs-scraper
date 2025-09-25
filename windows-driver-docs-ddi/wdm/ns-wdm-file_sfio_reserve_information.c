typedef struct _FILE_SFIO_RESERVE_INFORMATION {
  ULONG   RequestsPerPeriod;
  ULONG   Period;
  BOOLEAN RetryFailures;
  BOOLEAN Discardable;
  ULONG   RequestSize;
  ULONG   NumOutstandingRequests;
} FILE_SFIO_RESERVE_INFORMATION, *PFILE_SFIO_RESERVE_INFORMATION;