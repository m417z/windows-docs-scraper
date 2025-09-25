# IOCTL_SERIAL_PURGE IOCTL

## Description

The **IOCTL_SERIAL_PURGE** request cancels the specified requests and deletes data from the specified buffers. The purge request can be used to cancel all read requests and write requests and to delete all data from the receive buffer and the transmit buffer.

The completion of the purge request does not indicate that the requests canceled by the purge request are completed. A client must verify that the purged requests are completed before the client frees or reuses the corresponding IRPs.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated ULONG that is used to input a *purge mask*. The client sets the purge mask to a bitwise-OR of one or more of the following purge flags:

SERIAL_PURGE_RXABORT

Purges all read (IRP_MJ_READ) requests.

SERIAL_PURGE_RXCLEAR

Purges the receive buffer, if one exists.

SERIAL_PURGE_TXABORT

Purges all write (IRP_MJ_WRITE) requests.

SERIAL_PURGE_TXCLEAR

Purges the transmit buffer, if one exists.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a ULONG.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a ULONG. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates that the purge mask is not valid.

## -SERIAL_PURGE_RXABORT

Purges all read ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) requests.

## -SERIAL_PURGE_RXCLEAR

Purges the receive buffer, if one exists.

## -SERIAL_PURGE_TXABORT

Purges all write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) requests.

## -SERIAL_PURGE_TXCLEAR

Purges the transmit buffer, if one exists.

## Remarks

Serial.sys and SerCx allow an **IOCTL_SERIAL_PURGE** request to specify any combination of one or more SERIAL_PURGE_*XXX* flags. However, SerCx2 is more restrictive.

SerCx2 requires that all read requests be purged if the receive buffer is purged. Thus, if the SERIAL_PURGE_RXCLEAR flag is set in an **IOCTL_SERIAL_PURGE** request, then either the SerCx2 I/O request queue must not contain any read requests, or the SERIAL_PURGE_RXABORT flag must be set. Otherwise, the **IOCTL_SERIAL_PURGE** request fails with a STATUS_INVALID_DEVICE_STATE status code.

Similarly, SerCx2 requires that all write requests be purged if the transmit buffer is purged. Thus, if the SERIAL_PURGE_TXCLEAR flag is set in an **IOCTL_SERIAL_PURGE** request, then either the SerCx2 I/O request queue must not contain any write requests, or the SERIAL_PURGE_TXABORT flag must be set. Otherwise, the **IOCTL_SERIAL_PURGE** request fails with a STATUS_INVALID_DEVICE_STATE status code.

For more information about SerCx2, SerCx, and Serial.sys, see [Serial Controller Drivers Overview](https://learn.microsoft.com/previous-versions/jj241971(v=vs.85)).