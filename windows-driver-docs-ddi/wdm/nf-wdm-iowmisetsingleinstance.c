NTSTATUS IoWMISetSingleInstance(
  [in] PVOID           DataBlockObject,
  [in] PUNICODE_STRING InstanceName,
  [in] ULONG           Version,
  [in] ULONG           ValueBufferSize,
  [in] PVOID           ValueBuffer
);