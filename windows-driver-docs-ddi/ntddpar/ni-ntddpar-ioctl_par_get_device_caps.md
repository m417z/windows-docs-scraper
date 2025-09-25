# IOCTL_PAR_GET_DEVICE_CAPS IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_PAR_GET_DEVICE_CAPS request does the following:

* Specifies the protocols that the system-supplied bus driver for parallel ports must not use with a parallel device
* Returns the operating protocols that the parallel device supports

For more information, see [Setting and Clearing a Communication Mode for a Parallel Device](https://learn.microsoft.com/previous-versions/ff544797(v=vs.85)).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a USHORT buffer that the client allocates to input and output mode information. The request sets the input buffer to a bitwise OR of the modes that the parallel port bus driver must not use with a parallel device.

### Input buffer length

The length of a USHORT.

### Output buffer

**AssociatedIrp.SystemBuffer** points to the USHORT buffer that the parallel port bus driver uses to output mode information. The parallel port bus driver sets the buffer to indicate which operating protocols the parallel device supports.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a USHORT.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size, in bytes, of a USHORT.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to the following value:

**STATUS_BUFFER_TOO_SMALL**

The **Parameters.DeviceIoControl.OutputBufferLength** member is less than the size, in bytes, of a USHORT.

## See also

[IOCTL_IEEE1284_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_get_mode)

[IOCTL_IEEE1284_NEGOTIATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_negotiate)