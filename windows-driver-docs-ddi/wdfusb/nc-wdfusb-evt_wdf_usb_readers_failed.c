EVT_WDF_USB_READERS_FAILED EvtWdfUsbReadersFailed;

BOOLEAN EvtWdfUsbReadersFailed(
  [in] WDFUSBPIPE Pipe,
  [in] NTSTATUS Status,
  [in] USBD_STATUS UsbdStatus
)
{...}