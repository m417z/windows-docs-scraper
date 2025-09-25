# USB_USER_ERROR_CODE enumeration

## Description

The **USB_USER_ERROR_CODE** enumeration lists the error codes that a USB user-mode request reports when it fails.

## Constants

### `UsbUserSuccess:0`

The user request succeeded.

### `UsbUserNotSupported`

The user request was not supported.

### `UsbUserInvalidRequestCode`

The user request code was invalid.

### `UsbUserFeatureDisabled`

The feature that was specified by user request is disabled.

### `UsbUserInvalidHeaderParameter`

The user request contains an invalid header parameter.

### `UsbUserInvalidParameter`

The user request contains an invalid parameter.

### `UsbUserMiniportError`

The user request failed because of a miniport driver error.

### `UsbUserBufferTooSmall`

The user request failed because the data buffer was too small.

### `UsbUserErrorNotMapped`

The USB stack could not map the error to one of the errors that are listed in this enumeration.

### `UsbUserDeviceNotStarted`

The device was not started.

### `UsbUserNoDeviceConnected`

The device was not connected.

## See also

[USB Constants and Enumerations](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)