KSDDKAPI NTSTATUS KsInitializeDriver(
  [in]           PDRIVER_OBJECT            DriverObject,
  [in]           PUNICODE_STRING           RegistryPathName,
  [in, optional] const KSDEVICE_DESCRIPTOR *Descriptor
);