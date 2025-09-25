# IOCTL_SERIAL_SET_BAUD_RATE IOCTL

## Description

The **IOCTL_SERIAL_SET_BAUD_RATE** request sets the baud rate on a serial controller device. The serial controller driver verifies the specified baud rate.

To obtain the baud rate, a client can use an [IOCTL_SERIAL_GET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_baud_rate) request.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [SERIAL_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_baud_rate) structure that a client allocates and sets to input the baud rate.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a [SERIAL_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_baud_rate) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[IOCTL_SERIAL_GET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_baud_rate)

[SERIAL_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_baud_rate)