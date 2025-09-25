NTSTATUS IoEnumerateDeviceObjectList(
  [in]  PDRIVER_OBJECT DriverObject,
  [out] PDEVICE_OBJECT *DeviceObjectList,
  [in]  ULONG          DeviceObjectListSize,
  [out] PULONG         ActualNumberDeviceObjects
);