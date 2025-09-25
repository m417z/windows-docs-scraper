PORTCLASSAPI NTSTATUS PcGetDeviceProperty(
  [in]  PVOID                    DeviceObject,
  [in]  DEVICE_REGISTRY_PROPERTY DeviceProperty,
  [in]  ULONG                    BufferLength,
  [out] PVOID                    PropertyBuffer,
  [out] PULONG                   ResultLength
);