NTSTATUS UcxUsbDeviceCreate(
  [in]           UCXCONTROLLER          Controller,
  [out]          PUCXUSBDEVICE_INIT     *UsbDeviceInit,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          UCXUSBDEVICE           *UsbDevice
);