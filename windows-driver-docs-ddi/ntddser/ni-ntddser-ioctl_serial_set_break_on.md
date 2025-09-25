# IOCTL_SERIAL_SET_BREAK_ON IOCTL

## Description

The **IOCTL_SERIAL_SET_BREAK_ON** request sets the line control break signal active.

To set the line control break signal inactive, a client can use an [IOCTL_SERIAL_SET_BREAK_OFF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_break_off) request.

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

[IOCTL_SERIAL_SET_BREAK_OFF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_break_off)