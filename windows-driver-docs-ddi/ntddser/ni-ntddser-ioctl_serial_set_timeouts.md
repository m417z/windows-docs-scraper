# IOCTL_SERIAL_SET_TIMEOUTS IOCTL

## Description

The **IOCTL_SERIAL_SET_TIMEOUTS** request sets the time-out values that the serial controller driver uses for read and write requests.

To get the time-out values, a client can use an [IOCTL_SERIAL_GET_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_timeouts) request.

For more information about time-outs, see [Setting Read and Write Time-Outs for a Serial Device](https://learn.microsoft.com/previous-versions/ff547486(v=vs.85)).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated [SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts) structure that is used to input read and write time-out values.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a **SERIAL_TIMEOUTS** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates that the read time-out values exceed the maximum permitted values.

## See also

[IOCTL_SERIAL_GET_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_timeouts)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)