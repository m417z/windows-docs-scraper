VOID RxLogEventWithAnnotation(
  [in] IN PRDBSS_DEVICE_OBJECT DeviceObject,
       IN ULONG                EventId,
       IN NTSTATUS             Status,
       IN PVOID                DataBuffer,
       IN USHORT               DataBufferLength,
       IN PUNICODE_STRING      Annotation,
  [in] IN ULONG                AnnotationCount
);