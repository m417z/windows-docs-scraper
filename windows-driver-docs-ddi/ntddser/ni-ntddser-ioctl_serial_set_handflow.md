# IOCTL_SERIAL_SET_HANDFLOW IOCTL

## Description

The **IOCTL_SERIAL_SET_HANDFLOW** request sets the configuration of handshake flow control. The serial controller driver verifies the specified handshake flow control information.

To obtain handshake flow control information, a client can use an [IOCTL_SERIAL_GET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_handflow) request.

For more information about settings for handshake flow control, see [SERIAL_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_handflow).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated **SERIAL_HANDFLOW** structure that is used to input the handshake flow control information.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a **SERIAL_HANDFLOW** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates the specified handshake flow control is not valid.

## See also

[IOCTL_SERIAL_GET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_handflow)

[SERIAL_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_handflow)