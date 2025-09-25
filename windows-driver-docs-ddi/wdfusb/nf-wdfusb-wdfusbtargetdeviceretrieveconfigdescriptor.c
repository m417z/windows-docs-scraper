NTSTATUS WdfUsbTargetDeviceRetrieveConfigDescriptor(
  [in]      WDFUSBDEVICE UsbDevice,
  [out]     PVOID        ConfigDescriptor,
  [in, out] PUSHORT      ConfigDescriptorLength
);