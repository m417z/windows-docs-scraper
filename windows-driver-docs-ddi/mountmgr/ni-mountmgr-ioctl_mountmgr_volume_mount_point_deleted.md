## Description

The mount manager clients use this IOCTL to alert the mount manager that a volume mount point has been deleted so that the mount manager can replicate the database entry for the given mount point.

The Microsoft Win32 routine **DeleteVolumeMountPoint** sends this IOCTL to the mount manager, to inform the mount manager that a directory junction is no longer pointing to a volume name. The mount manager responds by deleting the volume name formerly contained in the directory junction along with its unique ID from the volume hosting the directory junction.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

The mount manager client initializes the [**MOUNTMGR_VOLUME_MOUNT_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_volume_mount_point) structure at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to ```sizeof(MOUNTMGR_VOLUME_MOUNT_POINT)```.

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

If **InputBufferLength** is less than ```sizeof(MOUNTMGR_VOLUME_MOUNT_POINT)```, the **Status** field is set to STATUS_INVALID_PARAMETER.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTMGR_VOLUME_MOUNT_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_volume_mount_point)