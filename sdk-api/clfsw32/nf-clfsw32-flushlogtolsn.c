CLFSUSER_API BOOL FlushLogToLsn(
  [in]                PVOID        pvMarshalContext,
  [in]                PCLFS_LSN    plsnFlush,
  [out, optional]     PCLFS_LSN    plsnLastFlushed,
  [in, out, optional] LPOVERLAPPED pOverlapped
);