NTSTATUS WdfUsbTargetDeviceQueryString(
  [in]            WDFUSBDEVICE              UsbDevice,
  [in, optional]  WDFREQUEST                Request,
  [in, optional]  PWDF_REQUEST_SEND_OPTIONS RequestOptions,
  [out, optional] PUSHORT                   String,
  [in, out]       PUSHORT                   NumCharacters,
  [in]            UCHAR                     StringIndex,
  [in, optional]  USHORT                    LangID
);