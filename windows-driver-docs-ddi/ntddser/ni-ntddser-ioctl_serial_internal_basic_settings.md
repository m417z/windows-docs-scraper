# IOCTL_SERIAL_INTERNAL_BASIC_SETTINGS IOCTL

## Description

The IOCTL_SERIAL_INTERNAL_BASIC_SETTINGS request sets a serial device to a basic operating mode. Serial's basic operating mode reads and writes one byte at a time, and does not use handshake flow control or time-outs. The basic operation mode is suitable for use by a driver that uses a subset of the 16550 UART interface. Examples of such drivers include a mouse driver or a graphics pad driver for older hardware that use a 16450 UART.

The IOCTL_SERIAL_INTERNAL_BASIC_SETTINGS request returns the operating mode settings that are in use just before Serial sets the basic operation mode. A client uses an [IOCTL_SERIAL_INTERNAL_RESTORE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_internal_restore_settings) request to restore a previous operating mode. A client should treat the operating mode settings as opaque. Serial does not verify the settings when the settings are restored. Note also that a replacement driver for Serial might implement a different set of basic settings.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** points to a client-allocated SERIAL_BASIC_SETTINGS structure that Serial uses to output the current configuration.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** is set to the size, in bytes, of a SERIAL_BASIC_SETTINGS structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of SERIAL_BASIC_SETTINGS. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). If **Status** is set to STATUS_BUFFER_TOO_SMALL, the value of **Parameters.DeviceIoControl.OutputLength** is less than the size, in bytes, of a SERIAL_BASIC_SETTINGS structure.

## See also

[IOCTL_SERIAL_INTERNAL_RESTORE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_internal_restore_settings)