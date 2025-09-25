CLFSUSER_API BOOL GetLogIoStatistics(
  [in]            HANDLE             hLog,
  [in, out]       PVOID              pvStatsBuffer,
  [in]            ULONG              cbStatsBuffer,
  [in]            CLFS_IOSTATS_CLASS eStatsClass,
  [out, optional] PULONG             pcbStatsWritten
);