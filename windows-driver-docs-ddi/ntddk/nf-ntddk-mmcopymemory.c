NTSTATUS MmCopyMemory(
  [in]  PVOID           TargetAddress,
  [in]  MM_COPY_ADDRESS SourceAddress,
  [in]  SIZE_T          NumberOfBytes,
  [in]  ULONG           Flags,
  [out] PSIZE_T         NumberOfBytesTransferred
);