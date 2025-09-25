typedef enum _WDF_USB_PIPE_TYPE {
  WdfUsbPipeTypeInvalid = 0,
  WdfUsbPipeTypeControl,
  WdfUsbPipeTypeIsochronous,
  WdfUsbPipeTypeBulk,
  WdfUsbPipeTypeInterrupt
} WDF_USB_PIPE_TYPE;