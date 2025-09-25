NTSYSAPI NTSTATUS ZwFreeVirtualMemory(
  [in]      HANDLE  ProcessHandle,
  [in, out] PVOID   *BaseAddress,
  [in, out] PSIZE_T RegionSize,
  [in]      ULONG   FreeType
);