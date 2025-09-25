NTSTATUS WdfDeviceQueryPropertyEx(
  [in]  WDFDEVICE                 Device,
  [in]  PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
  [in]  ULONG                     BufferLength,
  [out] PVOID                     PropertyBuffer,
  [out] PULONG                    RequiredSize,
  [out] PDEVPROPTYPE              Type
);