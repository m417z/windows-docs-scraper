VOID RxLogEventWithBufferDirect(
       IN PVOID           DeviceOrDriverObject,
  [in] IN PUNICODE_STRING OriginatorId,
  [in] IN ULONG           EventId,
  [in] IN NTSTATUS        Status,
  [in] IN PVOID           DataBuffer,
  [in] IN USHORT          DataBufferLength,
  [in] IN ULONG           LineNumber
);