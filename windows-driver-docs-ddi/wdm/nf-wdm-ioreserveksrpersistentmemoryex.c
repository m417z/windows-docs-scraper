NTSTATUS IoReserveKsrPersistentMemoryEx(
  PDRIVER_OBJECT  DriverObject,
  PDEVICE_OBJECT  PhysicalDeviceObject,
  PUNICODE_STRING PhysicalDeviceId,
  PUSHORT         DataTag,
  ULONG           DataVersion,
  SIZE_T          Size,
  ULONG           Flags,
  PVOID           *DataHandle
);