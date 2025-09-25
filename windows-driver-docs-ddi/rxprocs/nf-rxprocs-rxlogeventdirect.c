VOID RxLogEventDirect(
  [in] IN PRDBSS_DEVICE_OBJECT DeviceObject,
  [in] IN PUNICODE_STRING      OriginatorId,
  [in] IN ULONG                EventId,
  [in] IN NTSTATUS             Status,
  [in] IN ULONG                Line
);