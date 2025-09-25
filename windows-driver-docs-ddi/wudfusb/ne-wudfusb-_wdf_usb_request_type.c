typedef enum _WDF_USB_REQUEST_TYPE {
  WdfUsbRequestTypeInvalid,
  WdfUsbRequestTypeNoFormat,
  WdfUsbRequestTypeDeviceControlTransfer,
  WdfUsbRequestTypePipeWrite,
  WdfUsbRequestTypePipeRead
} WDF_USB_REQUEST_TYPE, *PWDF_USB_REQUEST_TYPE;