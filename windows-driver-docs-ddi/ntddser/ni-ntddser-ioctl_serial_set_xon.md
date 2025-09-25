# IOCTL_SERIAL_SET_XON IOCTL

## Description

The **IOCTL_SERIAL_SET_XON** request emulates the reception of a XON (transmit on) character, which restarts reception of data.

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

[IOCTL_SERIAL_SET_XOFF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_xoff)