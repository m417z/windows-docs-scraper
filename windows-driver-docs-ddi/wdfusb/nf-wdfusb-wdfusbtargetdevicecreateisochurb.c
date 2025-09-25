NTSTATUS WdfUsbTargetDeviceCreateIsochUrb(
  [in]            WDFUSBDEVICE           UsbDevice,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES Attributes,
  [in]            ULONG                  NumberOfIsochPackets,
  [out]           WDFMEMORY              *UrbMemory,
  [out, optional] PURB                   *Urb
);