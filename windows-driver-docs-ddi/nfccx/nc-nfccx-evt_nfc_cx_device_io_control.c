EVT_NFC_CX_DEVICE_IO_CONTROL EvtNfcCxDeviceIoControl;

VOID EvtNfcCxDeviceIoControl(
  [in] WDFDEVICE Device,
  [in] WDFREQUEST Request,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength,
  [in] ULONG IoControlCode
)
{...}