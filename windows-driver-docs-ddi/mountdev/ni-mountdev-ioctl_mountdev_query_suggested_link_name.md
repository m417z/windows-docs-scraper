## Description

**IOCTL_MOUNTDEV_QUERY_SUGGESTED_LINK_NAME** allows mount manager clients, such as device or volume drivers, to suggest a drive letter or link name for their associated volumes.

Support for this IOCTL by mount manager clients is optional.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The client driver must placed a variable-length structure of type [**MOUNTDEV_SUGGESTED_LINK_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ns-mountdev-_mountdev_suggested_link_name) at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**. The client driver must insert the suggested persistent name at the address pointed to by the **Name** member of this structure.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be greater than or equal to ```sizeof(MOUNTDEV_SUGGESTED_LINK_NAME)```.

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

If the operation is successful, the **Information** field is set to the total number of bytes returned and the **Status** field is set to STATUS_SUCCESS.

If **OutputBufferLength** is less than **sizeof**(MOUNTDEV_SUGGESTED_LINK_NAME), the **Status** field is set to STATUS_INVALID_PARAMETER.

If **OutputBufferLength** is less than the total length of output data, the **Status** field is set to STATUS_BUFFER_OVERFLOW and the **Information** field is set to **sizeof**(MOUNTDEV_SUGGESTED_LINK_NAME).

## Remarks

Some mount manager clients are able to keep track of their drive letters across reboots of the system without the help of the mount manager. Such clients can send a suggested drive letter name to the mount manager in response to this IOCTL. The mount manager uses the suggested name if the mount manager's database doesn't already contain a persistent drive letter name for the client's volume. Otherwise, it ignores the suggestion and uses the drive letter name in its persistent name database.

Drive letter names must include the full path of the symbolic link in object namespace and must have the traditional MS-DOS syntax. For instance, drive letter "D" must be represented in this manner: "\DosDevices\D:". The alternative symbolic link path of "\??\D:" can't be used, nor can abbreviations of the symbolic link such as "D:".

The implementer of this function must not thread synchronize and must not make blocking and/or Interprocess Communication (IPC) function calls.

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTDEV_SUGGESTED_LINK_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ns-mountdev-_mountdev_suggested_link_name)