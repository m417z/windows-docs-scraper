# DriverUnifiedPosHealthCheckLevel enumeration

## Description

This enumeration indicates the type of health check to be performed when CheckHealthAsync is called on a POS device.

## Constants

### `UnknownHealthCheckLevel`

The type of health check is not known.

### `POSInternal`

Performs a health check without altering the device. The device is tested by internal tests as far as possible.

### `External`

Performs a more thorough test which may affect the device. For example, a printer may produce some output.

### `Interactive`

May display a dialog box that displays test options and results so that you can test the device interactively.