NTSTATUS IoReportDetectedDevice(
  [in]           PDRIVER_OBJECT                 DriverObject,
  [in]           INTERFACE_TYPE                 LegacyBusType,
  [in]           ULONG                          BusNumber,
  [in]           ULONG                          SlotNumber,
  [in, optional] PCM_RESOURCE_LIST              ResourceList,
  [in, optional] PIO_RESOURCE_REQUIREMENTS_LIST ResourceRequirements,
  [in]           BOOLEAN                        ResourceAssigned,
  [in, out]      PDEVICE_OBJECT                 *DeviceObject
);