CLFSUSER_API NTSTATUS ClfsGetIoStatistics(
  [in]            PLOG_FILE_OBJECT   plfoLog,
  [in, out]       PVOID              pvStatsBuffer,
  [in]            ULONG              cbStatsBuffer,
  [in]            CLFS_IOSTATS_CLASS eStatsClass,
  [out, optional] PULONG             pcbStatsWritten
);