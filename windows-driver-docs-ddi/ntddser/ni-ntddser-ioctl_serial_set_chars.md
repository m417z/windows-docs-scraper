# IOCTL_SERIAL_SET_CHARS IOCTL

## Description

The **IOCTL_SERIAL_SET_CHARS** request sets the special characters that the serial controller driver uses for handshake flow control. This driver verifies the specified special characters.

To obtain the special characters, a client can use an [IOCTL_SERIAL_GET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_chars) request.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated [SERIAL_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_chars) structure that is used to input special characters.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a **SERIAL_CHARS** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates that **XoffChar** equals **XonChar**, or that one of them equals the handshake flow control escape character.

## See also

[IOCTL_SERIAL_GET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_chars)

[SERIAL_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_chars)