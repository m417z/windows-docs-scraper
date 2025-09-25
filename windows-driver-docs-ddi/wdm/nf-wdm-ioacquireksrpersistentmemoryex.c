NTSTATUS IoAcquireKsrPersistentMemoryEx(
  PDRIVER_OBJECT  DriverObject,
  PDEVICE_OBJECT  PhysicalDeviceObject,
  PUNICODE_STRING PhysicalDeviceId,
  PUSHORT         DataTag,
  PULONG          DataVersion,
  PVOID           Buffer,
  PSIZE_T         Size
);