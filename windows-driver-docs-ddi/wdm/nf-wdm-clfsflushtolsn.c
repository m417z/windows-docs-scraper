CLFSUSER_API NTSTATUS ClfsFlushToLsn(
  [in]            PVOID     pvMarshalContext,
  [in]            PCLFS_LSN plsnFlush,
  [out, optional] PCLFS_LSN plsnLastFlushed
);