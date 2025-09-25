__kernel_entry NTSYSCALLAPI NTSTATUS NtFsControlFile(
  [in]            HANDLE           FileHandle,
  [in, optional]  HANDLE           Event,
  [in, optional]  PIO_APC_ROUTINE  ApcRoutine,
  [in, optional]  PVOID            ApcContext,
  [out]           PIO_STATUS_BLOCK IoStatusBlock,
  [in]            ULONG            FsControlCode,
  [in, optional]  PVOID            InputBuffer,
  [in]            ULONG            InputBufferLength,
  [out, optional] PVOID            OutputBuffer,
  [in]            ULONG            OutputBufferLength
);