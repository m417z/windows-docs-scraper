USBC_START_DEVICE_CALLBACK UsbcStartDeviceCallback;

NTSTATUS UsbcStartDeviceCallback(
  [in]  PUSB_DEVICE_DESCRIPTOR DeviceDescriptor,
  [in]  PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
  [out] PUSBC_FUNCTION_DESCRIPTOR *FunctionDescriptorBuffer,
  [out] PULONG FunctionDescriptorBufferLength,
  [in]  PDEVICE_OBJECT FdoDeviceObject,
  [in]  PDEVICE_OBJECT PdoDeviceObject
)
{...}