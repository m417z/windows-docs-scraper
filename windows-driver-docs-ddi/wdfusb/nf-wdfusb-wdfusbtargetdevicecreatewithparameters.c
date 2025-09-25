NTSTATUS WdfUsbTargetDeviceCreateWithParameters(
  [in]           WDFDEVICE                     Device,
  [in]           PWDF_USB_DEVICE_CREATE_CONFIG Config,
  [in, optional] PWDF_OBJECT_ATTRIBUTES        Attributes,
  [out]          WDFUSBDEVICE                  *UsbDevice
);