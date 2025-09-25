__kernel_entry NTSYSCALLAPI NTSTATUS NtFlushBuffersFileEx(
  [in]  HANDLE           FileHandle,
  [in]  ULONG            Flags,
  [in]  PVOID            Parameters,
  [in]  ULONG            ParametersSize,
  [out] PIO_STATUS_BLOCK IoStatusBlock
);