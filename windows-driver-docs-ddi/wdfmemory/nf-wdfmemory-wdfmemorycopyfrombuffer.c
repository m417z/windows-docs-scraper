NTSTATUS WdfMemoryCopyFromBuffer(
  [in] WDFMEMORY DestinationMemory,
  [in] size_t    DestinationOffset,
  [in] PVOID     Buffer,
  [in] size_t    NumBytesToCopyFrom
);