PVOID MapViewOfFile2(
  [in]           HANDLE  FileMappingHandle,
  [in]           HANDLE  ProcessHandle,
  [in]           ULONG64 Offset,
  [in, optional] PVOID   BaseAddress,
  [in]           SIZE_T  ViewSize,
  [in]           ULONG   AllocationType,
  [in]           ULONG   PageProtection
);