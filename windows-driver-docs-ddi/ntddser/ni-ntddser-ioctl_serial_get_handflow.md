# IOCTL_SERIAL_GET_HANDFLOW IOCTL

## Description

The **IOCTL_SERIAL_GET_HANDFLOW** request returns information about the configuration of the handshake flow control set for a serial device.

To set the configuration of the handshake flow control, a client can use an [IOCTL_SERIAL_SET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_handflow) request.

For more information about the settings for handshake flow control, see [SERIAL_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_handflow).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated **SERIAL_HANDFLOW** structure that the serial controller driver uses to output information about the configuration of handshake flow control.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a **SERIAL_HANDFLOW** structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a **SERIAL_HANDFLOW** structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[IOCTL_SERIAL_SET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_handflow)

[SERIAL_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_handflow)