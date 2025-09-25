typedef enum _USB_USER_ERROR_CODE {
  UsbUserSuccess = 0,
  UsbUserNotSupported,
  UsbUserInvalidRequestCode,
  UsbUserFeatureDisabled,
  UsbUserInvalidHeaderParameter,
  UsbUserInvalidParameter,
  UsbUserMiniportError,
  UsbUserBufferTooSmall,
  UsbUserErrorNotMapped,
  UsbUserDeviceNotStarted,
  UsbUserNoDeviceConnected
} USB_USER_ERROR_CODE;