# IOCTL_SERIAL_GET_CHARS IOCTL

## Description

The **IOCTL_SERIAL_GET_CHARS** request retrieves the special characters that the serial controller driver uses with handshake flow control. The special characters are described by a [SERIAL_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_chars) structure.

To set special characters, a client can use an [IOCTL_SERIAL_SET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_chars) request.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated **SERIAL_CHARS** structure that the serial controller driver uses to output the special characters.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size in bytes of a **SERIAL_CHARS** structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size in bytes of **SERIAL_CHARS**. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[IOCTL_SERIAL_SET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_chars)

[SERIAL_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_chars)