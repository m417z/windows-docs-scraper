NTSTATUS IoReserveKsrPersistentMemory(
  PDRIVER_OBJECT DriverObject,
  PDEVICE_OBJECT PhysicalDeviceObject,
  SIZE_T         Size,
  ULONG          Flags,
  PVOID          *DataHandle
);