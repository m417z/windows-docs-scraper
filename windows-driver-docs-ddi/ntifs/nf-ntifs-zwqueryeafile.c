NTSTATUS ZwQueryEaFile(
  [in]           HANDLE           FileHandle,
  [out]          PIO_STATUS_BLOCK IoStatusBlock,
  [out]          PVOID            Buffer,
  [in]           ULONG            Length,
  [in]           BOOLEAN          ReturnSingleEntry,
  [in, optional] PVOID            EaList,
  [in]           ULONG            EaListLength,
  [in, optional] PULONG           EaIndex,
  [in]           BOOLEAN          RestartScan
);