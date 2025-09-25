__kernel_entry NTSYSCALLAPI NTSTATUS NtCopyFileChunk(
  [in]           HANDLE           SourceHandle,
  [in]           HANDLE           DestHandle,
  [in, optional] HANDLE           Event,
  [out]          PIO_STATUS_BLOCK IoStatusBlock,
  [in]           ULONG            Length,
  [in]           PLARGE_INTEGER   SourceOffset,
  [in]           PLARGE_INTEGER   DestOffset,
  [in, optional] PULONG           SourceKey,
  [in, optional] PULONG           DestKey,
  [in]           ULONG            Flags
);