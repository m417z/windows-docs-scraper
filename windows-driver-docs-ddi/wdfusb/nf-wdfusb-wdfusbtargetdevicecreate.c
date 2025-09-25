NTSTATUS WdfUsbTargetDeviceCreate(
  [in]           WDFDEVICE              Device,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          WDFUSBDEVICE           *UsbDevice
);