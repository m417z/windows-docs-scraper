KSDDKAPI NTSTATUS KsInitializeDevice(
  [in]           PDEVICE_OBJECT            FunctionalDeviceObject,
  [in]           PDEVICE_OBJECT            PhysicalDeviceObject,
  [in]           PDEVICE_OBJECT            NextDeviceObject,
  [in, optional] const KSDEVICE_DESCRIPTOR *Descriptor
);