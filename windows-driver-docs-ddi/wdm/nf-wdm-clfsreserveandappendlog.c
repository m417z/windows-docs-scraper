CLFSUSER_API NTSTATUS ClfsReserveAndAppendLog(
  [in]            PVOID             pvMarshalContext,
  [in, optional]  PCLFS_WRITE_ENTRY rgWriteEntries,
  [in]            ULONG             cWriteEntries,
  [in, optional]  PCLFS_LSN         plsnUndoNext,
  [in, optional]  PCLFS_LSN         plsnPrevious,
  [in]            ULONG             cReserveRecords,
  [in, out]       PLONGLONG         rgcbReservation,
  [in]            ULONG             fFlags,
  [out, optional] PCLFS_LSN         plsn
);