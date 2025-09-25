CLFSUSER_API BOOL ReserveAndAppendLogAligned(
  [in]                PVOID             pvMarshal,
  [in, optional]      PCLFS_WRITE_ENTRY rgWriteEntries,
  [in]                ULONG             cWriteEntries,
  [in]                ULONG             cbEntryAlignment,
  [in, optional]      PCLFS_LSN         plsnUndoNext,
  [in, optional]      PCLFS_LSN         plsnPrevious,
  [in]                ULONG             cReserveRecords,
  [in, out, optional] LONGLONG []       rgcbReservation,
  [in]                ULONG             fFlags,
  [out, optional]     PCLFS_LSN         plsn,
  [in, out, optional] LPOVERLAPPED      pOverlapped
);