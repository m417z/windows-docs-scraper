__kernel_entry NTSYSCALLAPI NTSTATUS NtLockFile(
  [in]           HANDLE           FileHandle,
  [in, optional] HANDLE           Event,
  [in, optional] PIO_APC_ROUTINE  ApcRoutine,
  [in, optional] PVOID            ApcContext,
  [out]          PIO_STATUS_BLOCK IoStatusBlock,
  [in]           PLARGE_INTEGER   ByteOffset,
  [in]           PLARGE_INTEGER   Length,
  [in]           ULONG            Key,
  [in]           BOOLEAN          FailImmediately,
  [in]           BOOLEAN          ExclusiveLock
);