# IOCTL_PAR_SET_READ_ADDRESS IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_PAR_SET_READ_ADDRESS request sets an extended capabilities port (ECP) or enhanced parallel port (EPP) read address (channel) for a parallel device.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a UCHAR buffer that the client allocates to input a read address. The request sets the buffer to an ECP or EPP read address.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a UCHAR.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to the following value:

**STATUS_INVALID_PARAMETER**

**Parameters.DeviceIoControl.InputBufferLength** is less than the size, in bytes, of a UCHAR.

## See also

[IOCTL_PAR_SET_WRITE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_set_write_address)