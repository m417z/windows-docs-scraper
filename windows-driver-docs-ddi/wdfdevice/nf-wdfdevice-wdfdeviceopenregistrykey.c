NTSTATUS WdfDeviceOpenRegistryKey(
  [in]           WDFDEVICE              Device,
  [in]           ULONG                  DeviceInstanceKeyType,
  [in]           ACCESS_MASK            DesiredAccess,
  [in, optional] PWDF_OBJECT_ATTRIBUTES KeyAttributes,
  [out]          WDFKEY                 *Key
);