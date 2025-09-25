NTSTATUS UdecxUsbDeviceCreate(
  [in, out]      PUDECXUSBDEVICE_INIT   *UdecxUsbDeviceInit,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          UDECXUSBDEVICE         *UdecxUsbDevice
);