# IOCTL_DISK_INTERNAL_SET_VERIFY IOCTL

## Description

Allows a driver to set the verify bit on a disk device object if the mode of the caller is kernel mode.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

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

The **Status** field is set to STATUS_SUCCESS. If the mode of the requester is not kernel mode, the requested operation is not performed, but STATUS_SUCCESS is still returned.

## See also

[IOCTL_DISK_INTERNAL_CLEAR_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_internal_clear_verify)