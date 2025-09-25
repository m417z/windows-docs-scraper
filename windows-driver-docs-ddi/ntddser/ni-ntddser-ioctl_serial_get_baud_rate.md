# IOCTL_SERIAL_GET_BAUD_RATE IOCTL

## Description

The **IOCTL_SERIAL_GET_BAUD_RATE** request returns the baud rate at which the serial port is currently configured to transmit and receive data.

To set the baud rate, a client can use an [IOCTL_SERIAL_SET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_baud_rate) request.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated **SERIAL_BAUD_RATE** structure that the serial controller driver uses to output the baud rate information.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size in bytes of a [SERIAL_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_baud_rate) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size in bytes of a [SERIAL_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_baud_rate) structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[IOCTL_SERIAL_SET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_baud_rate)

[SERIAL_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_baud_rate)