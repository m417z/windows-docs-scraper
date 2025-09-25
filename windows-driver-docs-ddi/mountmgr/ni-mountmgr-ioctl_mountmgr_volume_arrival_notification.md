## Description

This IOCTL allows a client to simulate a Plug and Play device interface arrival notification with the given volume name. If a client does not register a device interface of type MOUNTDEV_MOUNTED_DEVICE_GUID, the mount manager is not alerted of its arrival. However, the client can alert the mount manager of its volume's arrival directly by means of this IOCTL.

This IOCTL allows clients to obtain drive letters for newly created volumes during text mode setup when the Plug and Play device installer is not running.

Clients that have registered a device interface of type MOUNTDEV_MOUNTED_DEVICE_GUID in the normal way should not use this IOCTL.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

The mount manager client loads the following structure with the nonpersistent target device name. The initialized structure, [**MOUNTMGR_TARGET_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_target_name) is inserted at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

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