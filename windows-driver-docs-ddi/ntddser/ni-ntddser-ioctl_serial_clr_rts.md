# IOCTL_SERIAL_CLR_RTS IOCTL

## Description

The **IOCTL_SERIAL_CLR_RTS** request clears the *request to send* (RTS) control signal.

To set RTS, a client can use an [IOCTL_SERIAL_SET_RTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_rts) request.

If the handshake flow control of the device is configured to automatically use RTS, a client cannot clear or set RTS.

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

## -The Status member is set to one of the Generic Status Values for Serial Device Control Requests. A status of STATUS_INVALID_PARAMETER indicates that the handshake flow control of the device is set to automatically use RTS.

## See also

[IOCTL_SERIAL_SET_RTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_rts)