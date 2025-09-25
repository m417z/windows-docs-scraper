CLFSUSER_API BOOL ReadNextLogRecord(
  [in, out]           PVOID             pvReadContext,
  [out]               PVOID             *ppvBuffer,
  [out]               PULONG            pcbBuffer,
  [in, out]           PCLFS_RECORD_TYPE peRecordType,
  [in, optional]      PCLFS_LSN         plsnUser,
  [out]               PCLFS_LSN         plsnUndoNext,
  [out]               PCLFS_LSN         plsnPrevious,
  [out]               PCLFS_LSN         plsnRecord,
  [in, out, optional] LPOVERLAPPED      pOverlapped
);