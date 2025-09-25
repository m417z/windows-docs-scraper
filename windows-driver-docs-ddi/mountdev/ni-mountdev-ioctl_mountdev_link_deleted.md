## Description

**IOCTL_MOUNTDEV_LINK_DELETED** alerts the mount manager client that a persistent name associated with it has been deleted.

Support for this IOCTL by mount manager clients is optional.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

The mount manager places a variable-length structure of type [**MOUNTDEV_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountdev_name) at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**. The mount manager inserts the persistent name just assigned at the address pointed to by the **Name** member of this structure.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to ```sizeof(MOUNTDEV_NAME)```.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

No status.

## Remarks

The implementer of this function must not thread synchronize and must not make blocking and/or Interprocess Communication (IPC) function calls.

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTDEV_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountdev_name)