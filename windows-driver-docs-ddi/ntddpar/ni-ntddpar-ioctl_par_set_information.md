# IOCTL_PAR_SET_INFORMATION IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_PAR_SET_INFORMATION request resets and initializes a parallel device.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [PAR_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_set_information) structure that the client allocates to input set information. The client sets the **Init** member to PARALLEL_INIT.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a PAR_SET_INFORMATION structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

**Parameters.DeviceIoControl.InputBufferLength** is less than the size, in bytes, of a PAR_SET_INFORMATION structure.

**STATUS_DEVICE_NOT_CONNECTED**

The device is not connected.

**STATUS_DEVICE_OFF_LINE**

The device is offline.

**STATUS_DEVICE_PAPER_EMPTY**

The device is out of paper.

**STATUS_DEVICE_POWERED_OFF**

The device is not turned on.

## See also

[IOCTL_PAR_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_information)

[PAR_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_set_information)