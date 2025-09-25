typedef enum _WDF_USB_BMREQUEST_RECIPIENT {
  BmRequestToDevice = 0,
  BmRequestToInterface,
  BmRequestToEndpoint,
  BmRequestToOther
} WDF_USB_BMREQUEST_RECIPIENT;