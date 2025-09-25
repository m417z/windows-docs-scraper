NTSTATUS WdfUsbTargetDeviceFormatRequestForUrb(
  [in]           WDFUSBDEVICE      UsbDevice,
  [in]           WDFREQUEST        Request,
  [in]           WDFMEMORY         UrbMemory,
  [in, optional] PWDFMEMORY_OFFSET UrbMemoryOffset
);