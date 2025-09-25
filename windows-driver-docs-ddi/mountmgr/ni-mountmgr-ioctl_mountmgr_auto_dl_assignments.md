## Description

IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS informs the mount manager that it should assign drive letters to volumes automatically as they are introduced in the system.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

If the operation is successful, the **Status** field is set to STATUS_SUCCESS.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).