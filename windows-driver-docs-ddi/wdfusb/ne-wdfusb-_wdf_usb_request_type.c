typedef enum _WDF_USB_REQUEST_TYPE {
  WdfUsbRequestTypeInvalid = 0,
  WdfUsbRequestTypeNoFormat,
  WdfUsbRequestTypeDeviceString,
  WdfUsbRequestTypeDeviceControlTransfer,
  WdfUsbRequestTypeDeviceUrb,
  WdfUsbRequestTypePipeWrite,
  WdfUsbRequestTypePipeRead,
  WdfUsbRequestTypePipeAbort,
  WdfUsbRequestTypePipeReset,
  WdfUsbRequestTypePipeUrb
} WDF_USB_REQUEST_TYPE, *PWDF_USB_REQUEST_TYPE;