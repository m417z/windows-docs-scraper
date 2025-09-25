# IOCTL_SERIAL_CLEAR_STATS IOCTL

## Description

The **IOCTL_SERIAL_CLEAR_STATS** request clears the performance statistics for a serial device.

To obtain the performance statistics, a client can use an [IOCTL_SERIAL_GET_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_stats) request.

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

The **Information** field is set to zero.

The **Status** field is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2).

## See also

[IOCTL_SERIAL_GET_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_stats)