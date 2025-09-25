NTSTATUS IoOpenDeviceRegistryKey(
  [in]  PDEVICE_OBJECT DeviceObject,
  [in]  ULONG          DevInstKeyType,
  [in]  ACCESS_MASK    DesiredAccess,
  [out] PHANDLE        DeviceRegKey
);