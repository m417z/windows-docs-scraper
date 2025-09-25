NTSTATUS WdfDeviceAssignInterfaceProperty(
  [in]           WDFDEVICE                           Device,
  [in]           PWDF_DEVICE_INTERFACE_PROPERTY_DATA PropertyData,
  [in]           DEVPROPTYPE                         Type,
  [in]           ULONG                               BufferLength,
  [in, optional] PVOID                               PropertyBuffer
);