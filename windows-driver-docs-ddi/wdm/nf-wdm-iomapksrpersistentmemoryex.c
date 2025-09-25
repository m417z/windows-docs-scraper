NTSTATUS IoMapKsrPersistentMemoryEx(
  PDRIVER_OBJECT  DriverObject,
  PDEVICE_OBJECT  PhysicalDeviceObject,
  PUNICODE_STRING PhysicalDeviceId,
  PUSHORT         DataTag,
  PULONG          DataVersion,
  PVOID           *DataHandle
);