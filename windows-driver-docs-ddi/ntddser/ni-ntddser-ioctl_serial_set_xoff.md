# IOCTL_SERIAL_SET_XOFF IOCTL

## Description

The **IOCTL_SERIAL_SET_XOFF** request emulates the reception of an XOFF (transmit off) character. The request stops reception of data. If automatic XON/XOFF flow control is not set, then a client must use a subsequent [IOCTL_SERIAL_SET_XON](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_xon) request to restart reception of data.

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

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[IOCTL_SERIAL_SET_XON](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_xon)