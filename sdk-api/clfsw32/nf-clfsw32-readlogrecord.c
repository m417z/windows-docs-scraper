CLFSUSER_API BOOL ReadLogRecord(
  [in]                PVOID             pvMarshal,
  [in]                PCLFS_LSN         plsnFirst,
  [in]                CLFS_CONTEXT_MODE eContextMode,
  [out]               PVOID             *ppvReadBuffer,
  [out]               PULONG            pcbReadBuffer,
  [out]               PCLFS_RECORD_TYPE peRecordType,
  [out]               PCLFS_LSN         plsnUndoNext,
  [out]               PCLFS_LSN         plsnPrevious,
  [out]               PVOID             *ppvReadContext,
  [in, out, optional] LPOVERLAPPED      pOverlapped
);