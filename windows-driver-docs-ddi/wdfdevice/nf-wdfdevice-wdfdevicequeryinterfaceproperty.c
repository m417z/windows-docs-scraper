NTSTATUS WdfDeviceQueryInterfaceProperty(
  [in]  WDFDEVICE                           Device,
  [in]  PWDF_DEVICE_INTERFACE_PROPERTY_DATA PropertyData,
  [in]  ULONG                               BufferLength,
  [out] PVOID                               PropertyBuffer,
  [out] PULONG                              ResultLength,
  [out] PDEVPROPTYPE                        Type
);