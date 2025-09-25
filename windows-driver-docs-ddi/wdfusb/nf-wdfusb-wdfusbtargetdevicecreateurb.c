NTSTATUS WdfUsbTargetDeviceCreateUrb(
  [in]            WDFUSBDEVICE           UsbDevice,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]           WDFMEMORY              *UrbMemory,
  [out, optional] PURB                   *Urb
);