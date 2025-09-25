NTSYSAPI NTSTATUS ZwFlushVirtualMemory(
  [in]      HANDLE           ProcessHandle,
  [in, out] PVOID            *BaseAddress,
  [in, out] PSIZE_T          RegionSize,
  [out]     PIO_STATUS_BLOCK IoStatus
);