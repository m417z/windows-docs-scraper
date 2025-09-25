# DriverUnifiedPosErrorReason enumeration

## Description

This enumeration indicates the reason for the error.

## Constants

### `UnknownErrorReason`

The reason for the error is not known.

### `NoService`

Cannot communicate with the device due to the current configuration.

### `Disabled`

The device must be enabled in order to perform the operation.

### `Illegal`

The function is not available or is not supported on this device.

### `NoHardware`

The physical device is not connected or not powered on.

### `Closed`

The device is closed.

### `Offline`

The device is offline.

### `Failure`

The device is connected and powered on, but it failed to perform the operation.

### `Timeout`

The operation timed out on the device.

### `Busy`

The device is busy and cannot complete the operation.

### `Extended`

The device returned a vendor specified error.