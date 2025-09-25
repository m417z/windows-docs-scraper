NTSYSAPI NTSTATUS ZwUnlockFile(
  [in]  HANDLE           FileHandle,
  [out] PIO_STATUS_BLOCK IoStatusBlock,
  [in]  PLARGE_INTEGER   ByteOffset,
  [in]  PLARGE_INTEGER   Length,
  [in]  ULONG            Key
);