typedef struct _USBUSER_REQUEST_HEADER {
  ULONG               UsbUserRequest;
  USB_USER_ERROR_CODE UsbUserStatusCode;
  ULONG               RequestBufferLength;
  ULONG               ActualBufferLength;
} USBUSER_REQUEST_HEADER, *PUSBUSER_REQUEST_HEADER;