NTSYSAPI NTSTATUS ZwWriteFile(
  [in]           HANDLE           FileHandle,
  [in, optional] HANDLE           Event,
  [in, optional] PIO_APC_ROUTINE  ApcRoutine,
  [in, optional] PVOID            ApcContext,
  [out]          PIO_STATUS_BLOCK IoStatusBlock,
  [in]           PVOID            Buffer,
  [in]           ULONG            Length,
  [in, optional] PLARGE_INTEGER   ByteOffset,
  [in, optional] PULONG           Key
);