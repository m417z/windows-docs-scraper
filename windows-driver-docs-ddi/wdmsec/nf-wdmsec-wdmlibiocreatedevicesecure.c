NTSTATUS WdmlibIoCreateDeviceSecure(
  [in]           PDRIVER_OBJECT   DriverObject,
  [in]           ULONG            DeviceExtensionSize,
  [in, optional] PUNICODE_STRING  DeviceName,
  [in]           DEVICE_TYPE      DeviceType,
  [in]           ULONG            DeviceCharacteristics,
  [in]           BOOLEAN          Exclusive,
  [in]           PCUNICODE_STRING DefaultSDDLString,
  [in, optional] LPCGUID          DeviceClassGuid,
                 PDEVICE_OBJECT   *DeviceObject
);