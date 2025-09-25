KSDDKAPI NTSTATUS KsCreateDevice(
  [in]            PDRIVER_OBJECT            DriverObject,
  [in]            PDEVICE_OBJECT            PhysicalDeviceObject,
  [in, optional]  const KSDEVICE_DESCRIPTOR *Descriptor,
  [in]            ULONG                     ExtensionSize,
  [out, optional] PKSDEVICE                 *Device
);