KSDDKAPI NTSTATUS KsCreateBusEnumObject(
  [in]           PWSTR          BusIdentifier,
  [in]           PDEVICE_OBJECT BusDeviceObject,
  [in]           PDEVICE_OBJECT PhysicalDeviceObject,
  [in, optional] PDEVICE_OBJECT PnpDeviceObject,
  [in, optional] REFGUID        InterfaceGuid,
  [in, optional] PWSTR          ServiceRelativePath
);