# DriverUnifiedPosErrorSeverity enumeration

## Description

This enumeration indicates the severity of the error.

## Constants

### `UnknownErrorSeverity`

The severity of the error is not known.

### `Warning`

The error or warning is informational.

### `Recoverable`

The device can recover from the error without closing the application or rebooting.

### `Unrecoverable`

The device is still working, but it must close the application to recover from the error.

### `AssistanceRequired`

Intervention is needed to respond to the error.

### `Fatal`

The error requires that the device be rebooted.