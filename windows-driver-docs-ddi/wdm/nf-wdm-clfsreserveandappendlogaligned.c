CLFSUSER_API NTSTATUS ClfsReserveAndAppendLogAligned(
  [in]            PVOID             pvMarshalContext,
  [in, optional]  PCLFS_WRITE_ENTRY rgWriteEntries,
  [in]            ULONG             cWriteEntries,
  [in]            ULONG             cbEntryAlignment,
  [in, optional]  PCLFS_LSN         plsnUndoNext,
  [in, optional]  PCLFS_LSN         plsnPrevious,
  [in]            ULONG             cReserveRecords,
  [in, out]       PLONGLONG         rgcbReservation,
  [in]            ULONG             fFlags,
  [out, optional] PCLFS_LSN         plsn
);