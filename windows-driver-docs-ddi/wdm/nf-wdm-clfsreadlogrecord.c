CLFSUSER_API NTSTATUS ClfsReadLogRecord(
  [in]      PVOID             pvMarshalContext,
  [in, out] PCLFS_LSN         plsnFirst,
  [in]      CLFS_CONTEXT_MODE peContextMode,
  [out]     PVOID             *ppvReadBuffer,
  [out]     PULONG            pcbReadBuffer,
  [out]     PCLFS_RECORD_TYPE peRecordType,
  [out]     PCLFS_LSN         plsnUndoNext,
  [out]     PCLFS_LSN         plsnPrevious,
  [out]     PVOID             *ppvReadContext
);