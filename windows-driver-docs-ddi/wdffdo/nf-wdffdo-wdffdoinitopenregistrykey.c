NTSTATUS WdfFdoInitOpenRegistryKey(
  [in]           PWDFDEVICE_INIT        DeviceInit,
  [in]           ULONG                  DeviceInstanceKeyType,
  [in]           ACCESS_MASK            DesiredAccess,
  [in, optional] PWDF_OBJECT_ATTRIBUTES KeyAttributes,
  [out]          WDFKEY                 *Key
);