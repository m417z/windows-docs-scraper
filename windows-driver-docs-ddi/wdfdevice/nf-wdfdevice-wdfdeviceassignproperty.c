NTSTATUS WdfDeviceAssignProperty(
  [in]           WDFDEVICE                 Device,
  [in]           PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
  [in]           DEVPROPTYPE               Type,
  [in]           ULONG                     Size,
  [in, optional] PVOID                     Data
);