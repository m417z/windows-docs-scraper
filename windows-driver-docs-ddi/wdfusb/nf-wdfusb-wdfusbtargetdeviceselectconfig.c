NTSTATUS WdfUsbTargetDeviceSelectConfig(
  [in]           WDFUSBDEVICE                         UsbDevice,
  [in, optional] PWDF_OBJECT_ATTRIBUTES               PipeAttributes,
  [in, out]      PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params
);