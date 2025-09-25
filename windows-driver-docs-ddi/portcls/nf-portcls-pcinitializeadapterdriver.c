PORTCLASSAPI NTSTATUS PcInitializeAdapterDriver(
  [in] PDRIVER_OBJECT     DriverObject,
  [in] PUNICODE_STRING    RegistryPathName,
  [in] PDRIVER_ADD_DEVICE AddDevice
);