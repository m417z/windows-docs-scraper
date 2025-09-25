# IOCTL_SERIAL_SET_LINE_CONTROL IOCTL

## Description

The **IOCTL_SERIAL_SET_LINE_CONTROL** request sets the line control register (LCR). The line control register controls the data size, the number of stop bits, and the parity.

To obtain the value of the line control register, a client can use an [IOCTL_SERIAL_GET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_line_control) request.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** points to a client-allocated [SERIAL_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_line_control) structure that is used to input line control information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** is set to the size, in bytes, of a **SERIAL_LINE_CONTROL** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates that the specified line control information is not valid.

## See also

[IOCTL_SERIAL_GET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_line_control)

[SERIAL_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_line_control)