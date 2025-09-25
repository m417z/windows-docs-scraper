NTSTATUS WdfMemoryCopyToBuffer(
  [in]  WDFMEMORY SourceMemory,
  [in]  size_t    SourceOffset,
  [out] PVOID     Buffer,
  [in]  size_t    NumBytesToCopyTo
);