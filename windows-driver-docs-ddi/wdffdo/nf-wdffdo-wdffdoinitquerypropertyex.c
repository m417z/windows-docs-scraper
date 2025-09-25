NTSTATUS WdfFdoInitQueryPropertyEx(
  [in]  PWDFDEVICE_INIT           DeviceInit,
  [in]  PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
  [in]  ULONG                     BufferLength,
  [out] PVOID                     PropertyBuffer,
  [out] PULONG                    ResultLength,
  [out] PDEVPROPTYPE              Type
);