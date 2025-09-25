NTSTATUS IoAllocateAdapterChannel(
  PADAPTER_OBJECT AdapterObject,
  PDEVICE_OBJECT  DeviceObject,
  ULONG           NumberOfMapRegisters,
  PDRIVER_CONTROL ExecutionRoutine,
  PVOID           Context
);