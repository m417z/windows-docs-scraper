NTSTATUS IoQueryKsrPersistentMemorySizeEx(
  PDRIVER_OBJECT  DriverObject,
  PDEVICE_OBJECT  PhysicalDeviceObject,
  PUNICODE_STRING PhysicalDeviceId,
  PUSHORT         DataTag,
  PULONG          DataVersion,
  PSIZE_T         BufferSize
);