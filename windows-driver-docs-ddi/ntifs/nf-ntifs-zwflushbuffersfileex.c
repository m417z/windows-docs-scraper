NTSYSAPI NTSTATUS ZwFlushBuffersFileEx(
  [in]  HANDLE           FileHandle,
        ULONG            FLags,
        PVOID            Parameters,
        ULONG            ParametersSize,
  [out] PIO_STATUS_BLOCK IoStatusBlock
);