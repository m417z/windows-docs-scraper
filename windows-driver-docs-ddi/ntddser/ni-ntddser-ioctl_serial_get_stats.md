# IOCTL_SERIAL_GET_STATS IOCTL

## Description

The **IOCTL_SERIAL_GET_STATS** request returns information about the performance of a serial controller. The statistics include the number of characters transmitted, the number of characters received, and useful error statistics. The driver continuously increments performance values.

To reset the accumulated performance values to zero, a client can use an [IOCTL_SERIAL_CLEAR_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clear_stats) request.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a client-allocated **SERIALPERF_STATS** structure that the serial controller driver uses to output performance information.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a [SERIALPERF_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serialperf_stats) structure.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[IOCTL_SERIAL_CLEAR_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clear_stats)

[SERIALPERF_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serialperf_stats)