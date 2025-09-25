# IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION IOCTL

## Description

The **IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION** control code configures the serial port to use the default hardware settings for the serial controller device. These settings are obtained from the ACPI resource descriptor for the serial controller device. For more information, see the [ACPI 5.0 specification](https://uefi.org/specifications).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [generic status values for serial device control requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_NOT_IMPLEMENTED indicates that the serial port does not support a default configuration. In this case, the client must use the other **IOCTL_SERIAL_*XXX*** I/O control requests to explicitly configure the serial port.

## Remarks

The client (application or peripheral device driver) sends this IOCTL to configure the serial port to use a set of default connection settings. These settings include connection-specific hardware parameters such as the baud rate, time-out values, and flow-control flags.

This IOCTL is supported by versions 1 and 2 of the serial framework extension (SerCx and SerCx2). Serial.sys, which manages the named serial ports (COM1, COM2, and so on) on a PC, does not support this IOCTL.

If a serial port does not support this IOCTL, the client must explicitly specify the connection settings for the port. That is, the client must send an [IOCTL_SERIAL_SET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_baud_rate) request to set the baud rate, send an [IOCTL_SERIAL_SET_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_timeouts) request to set the time-out intervals, and so on.

Immediately after a client opens a serial port, the client should assume that the port is configured in an unknown, uninitialized state rather than in some known, default state.

## See also

[IOCTL_SERIAL_SET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_baud_rate)

[IOCTL_SERIAL_SET_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_timeouts)