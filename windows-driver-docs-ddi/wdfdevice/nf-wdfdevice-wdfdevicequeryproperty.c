NTSTATUS WdfDeviceQueryProperty(
  [in]  WDFDEVICE                Device,
  [in]  DEVICE_REGISTRY_PROPERTY DeviceProperty,
  [in]  ULONG                    BufferLength,
  [out] PVOID                    PropertyBuffer,
  [out] PULONG                   ResultLength
);