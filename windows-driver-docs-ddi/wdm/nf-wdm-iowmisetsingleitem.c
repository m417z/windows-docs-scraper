NTSTATUS IoWMISetSingleItem(
  [in] PVOID           DataBlockObject,
  [in] PUNICODE_STRING InstanceName,
  [in] ULONG           DataItemId,
  [in] ULONG           Version,
  [in] ULONG           ValueBufferSize,
  [in] PVOID           ValueBuffer
);