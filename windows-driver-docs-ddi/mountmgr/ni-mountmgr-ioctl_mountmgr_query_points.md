## Description

This IOCTL returns triples that consist of a persistent symbolic link name for the volume (that is, a mount point), a unique ID for the volume, and a nonpersistent device name (such as "\Device\HarddiskVolume1") for the volume. The input to this IOCTL is a [**MOUNTMGR_MOUNT_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_mount_point) structure that contains a single triple.

If the input triple contains a unique ID or a non-persistent device name, the request retrieves all associated mount points (symbolic links), including the volume GUID pathname and the drive letters. However, if the input triple has a symbolic link, but does not specify either the unique ID or the device name, the request only returns a single triple that contains the symbolic link that was provided in the input, together with the unique ID and the device name. The caller must submit another IOCTL with either the unique ID or the device name to retrieve the remaining mount points.

If the input triple is empty, the mount manager returns the entire mounted device list.

The mount manager returns triples that match as much info as is provided by the caller. If the caller submits the unique ID, the mount manager returns all triples with that unique ID. If the caller inputs the volume pathname or a drive letter as the symbolic link name, the mount manager returns only the triple for the symbolic link. There is one entry per symbolic link. If the caller inputs a device pathname, the mount manager returns only the triples for that device pathname. If the caller inputs a unique ID and a symbolic link, again, the mount manager returns only one entry for that symbolic link. A caller would do this to get the device pathname. If the caller inputs no device pathname, unique ID or symbolic link, the mount manager returns all entries/triples.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

The mount manager client initializes the [**MOUNTMGR_MOUNT_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_mount_point) structure at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**. Immediately following this structure, the MM client loads the symbolic link name, the unique ID and the device name, in that order.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to ```sizeof(MOUNTMGR_MOUNT_POINT)```.

### Output buffer

The mount manager initializes a variable-length structure of type [**MOUNTMGR_MOUNT_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_mount_points) at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**. The mount manager inserts the mount points, associated with the indicated volume, at the address pointed to by the **MountPoints[]** member of this structure. Each mount point is represented by a MOUNTMGR_MOUNT_POINT structure as defined in the **Input** section for this IOCTL.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be greater than or equal to ```sizeof(MOUNTMGR_MOUNT_POINTS)```.

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

If the operation is successful, the **Status** field is set to STATUS_SUCCESS.

If neither the unique ID nor the nonpersistent device name are found in the volumes mounted device list, the **Status** field is set to STATUS_INVALID_PARAMETER.

If **InputBufferLength** is less than ```sizeof(MOUNTMGR_MOUNT_POINT)```, the **Status** field is set to STATUS_INVALID_PARAMETER.

If **InputBufferLength** is less than the total length of the three input ID strings, the **Status** field is set to STATUS_INVALID_PARAMETER.

If **OutputBufferLength** is less than ```sizeof(MOUNTMGR_MOUNT_POINT)```, the **Status** field is set to STATUS_INVALID_PARAMETER.

If **OutputBufferLength** is less than ```sizeof(MOUNTMGR_MOUNT_POINTS)``` plus the sum of the sizes of the mount point triples, the **Status** field is set to STATUS_BUFFER_OVERFLOW.

If any of the three strings contained within any of the triples is aligned on an odd address (for example, address & 01 != 0), the **Status** field is set to STATUS_INVALID_PARAMETER.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTMGR_MOUNT_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_mount_points)