## Description

This IOCTL directs the mount manager to keep a symbolic link active after the Plug and Play manager has given notification that its corresponding volume has gone offline. When the volume goes back online, the mount manager reassigns the symbolic link to the volume. No other volume is allowed to claim the symbolic link while its original owner is offline.

Clusters use this IOCTL to ensure that a node can continue to access a volume with the same drive letter, even if the volume is not continually present in the system.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

The mount manager client loads the following structure with the symbolic link that will persist even after its volume is removed from the system. The initialized structure [**MOUNTMGR_TARGET_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_target_name) is inserted at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to ```sizeof(MOUNTMGR_TARGET_NAME)```.

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

The input buffer size, indicated by **InputBufferLength**, must be large enough to hold the structure MOUNTMGR_TARGET_NAME and the symbolic link name that follows it. If it is not large enough, the **Status** field is set to STATUS_INVALID_PARAMETER.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTMGR_TARGET_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_target_name)