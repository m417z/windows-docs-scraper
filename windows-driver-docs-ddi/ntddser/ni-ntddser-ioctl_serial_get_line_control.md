# IOCTL_SERIAL_GET_LINE_CONTROL IOCTL

## Description

The **IOCTL_SERIAL_GET_LINE_CONTROL** request returns information about the line control set for a serial device. The line control parameters include the number of stop bits, the number of data bits, and the parity.

To configure the line control, a client can use an [IOCTL_SERIAL_SET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_line_control) request.

For information about valid line control register settings, see [SERIAL_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_line_control).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated **SERIAL_LINE_CONTROL** structure that the serial controller driver uses to output information about the line control configuration.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a **SERIAL_LINE_CONTROL** structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a **SERIAL_LINE_CONTROL** structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[IOCTL_SERIAL_SET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_line_control)

[SERIAL_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_line_control)