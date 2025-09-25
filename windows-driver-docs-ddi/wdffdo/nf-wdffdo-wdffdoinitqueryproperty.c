NTSTATUS WdfFdoInitQueryProperty(
  [in]  PWDFDEVICE_INIT          DeviceInit,
  [in]  DEVICE_REGISTRY_PROPERTY DeviceProperty,
  [in]  ULONG                    BufferLength,
  [out] PVOID                    PropertyBuffer,
  [out] PULONG                   ResultLength
);