NTSYSAPI NTSTATUS ZwNotifyChangeKey(
  [in]            HANDLE           KeyHandle,
  [in, optional]  HANDLE           Event,
  [in, optional]  PIO_APC_ROUTINE  ApcRoutine,
  [in, optional]  PVOID            ApcContext,
  [out]           PIO_STATUS_BLOCK IoStatusBlock,
  [in]            ULONG            CompletionFilter,
  [in]            BOOLEAN          WatchTree,
  [out, optional] PVOID            Buffer,
  [in]            ULONG            BufferSize,
  [in]            BOOLEAN          Asynchronous
);