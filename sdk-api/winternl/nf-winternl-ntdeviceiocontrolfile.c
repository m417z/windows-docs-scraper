__kernel_entry NTSTATUS NtDeviceIoControlFile(
  [in]  HANDLE           FileHandle,
  [in]  HANDLE           Event,
  [in]  PIO_APC_ROUTINE  ApcRoutine,
  [in]  PVOID            ApcContext,
  [out] PIO_STATUS_BLOCK IoStatusBlock,
  [in]  ULONG            IoControlCode,
  [in]  PVOID            InputBuffer,
  [in]  ULONG            InputBufferLength,
  [out] PVOID            OutputBuffer,
  [in]  ULONG            OutputBufferLength
);