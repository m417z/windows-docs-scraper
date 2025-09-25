NTSYSAPI NTSTATUS ZwSetQuotaInformationFile(
  [in]  HANDLE           FileHandle,
  [out] PIO_STATUS_BLOCK IoStatusBlock,
  [in]  PVOID            Buffer,
  [in]  ULONG            Length
);