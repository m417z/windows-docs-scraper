NTSTATUS WdfUsbTargetDeviceFormatRequestForString(
  [in]           WDFUSBDEVICE      UsbDevice,
  [in]           WDFREQUEST        Request,
  [in]           WDFMEMORY         Memory,
  [in, optional] PWDFMEMORY_OFFSET Offset,
  [in]           UCHAR             StringIndex,
  [in, optional] USHORT            LangID
);