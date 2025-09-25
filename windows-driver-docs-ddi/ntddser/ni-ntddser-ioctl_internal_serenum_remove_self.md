# IOCTL_INTERNAL_SERENUM_REMOVE_SELF IOCTL

## Description

The IOCTL_INTERNAL_SERENUM_REMOVE_SELF request invalidates the bus relations of the filter DO that are associated with a target PDO. (Physically, this request invalidates the bus relations of the RS-232 port to which the target device is attached.)

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

The **Status** member is set to one of the following values:

**STATUS_DELETE_PENDING**

The device is in the process of being removed.

**STATUS_SUCCESS**

The request completed successfully.