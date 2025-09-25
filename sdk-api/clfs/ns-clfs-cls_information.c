typedef struct _CLS_INFORMATION {
  LONGLONG  TotalAvailable;
  LONGLONG  CurrentAvailable;
  LONGLONG  TotalReservation;
  ULONGLONG BaseFileSize;
  ULONGLONG ContainerSize;
  ULONG     TotalContainers;
  ULONG     FreeContainers;
  ULONG     TotalClients;
  ULONG     Attributes;
  ULONG     FlushThreshold;
  ULONG     SectorSize;
  CLS_LSN   MinArchiveTailLsn;
  CLS_LSN   BaseLsn;
  CLS_LSN   LastFlushedLsn;
  CLS_LSN   LastLsn;
  CLS_LSN   RestartLsn;
  GUID      Identity;
} CLS_INFORMATION, *PCLS_INFORMATION, *PPCLS_INFORMATION;