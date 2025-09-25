PORTCLASSAPI NTSTATUS PcAddAdapterDevice(
  [in] PDRIVER_OBJECT   DriverObject,
  [in] PDEVICE_OBJECT   PhysicalDeviceObject,
  [in] PCPFNSTARTDEVICE StartDevice,
  [in] ULONG            MaxObjects,
  [in] ULONG            DeviceExtensionSize
);