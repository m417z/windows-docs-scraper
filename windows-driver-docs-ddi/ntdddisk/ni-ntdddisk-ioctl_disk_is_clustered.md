# IOCTL_DISK_IS_CLUSTERED IOCTL

## Description

Allows a driver or application to determine if a disk is clustered.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a Boolean value, with **TRUE** indicating that the disk is clustered.

### Output buffer length

Length of a Boolean.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.