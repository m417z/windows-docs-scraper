# IOCTL_SERIAL_SET_DTR IOCTL

## Description

The **IOCTL_SERIAL_SET_DTR** request sets DTR (data terminal ready).

If the handshake flow control of the device is configured to automatically use DTR, a client cannot clear or set DTR.

To clear DTR, a client can use an [IOCTL_SERIAL_CLR_DTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clr_dtr) request.

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

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates that the handshake flow control of the device is set to automatically use DTR.

## See also

[IOCTL_SERIAL_CLR_DTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clr_dtr)