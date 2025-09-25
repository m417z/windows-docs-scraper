## Description

Upon receiving this IOCTL a client driver must provide the (nonpersistent) device (or target) name for the volume. The mount manager uses the *device name* returned by the client as the target of a symbolic link. An example of a device name would be "\Device\HarddiskVolume1".

Support for this IOCTL by the mount manager clients is mandatory.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The mount manager client returns a variable-length structure of type [**MOUNTDEV_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountdev_name) at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**. The device name must be inserted at the address pointed to by the **Name** member of this structure.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be greater than or equal to ```sizeof(MOUNTDEV_NAME)```.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to FIELD_OFFSET([**MOUNTDEV_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountdev_name), Name) + output->NameLength, or alternatively, output->NameLength + sizeof(USHORT), where output points to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

If the operation is successful, the mount manager client must set the **Information** field to the length of the NULL-terminated string containing the device name and the **Status** field to STATUS_SUCCESS.

If the output buffer is too small to hold the device name, the mount manager client must set the **Information** field to ```sizeof(MOUNTDEV_NAME)``` and the **Status** field to STATUS_BUFFER_OVERFLOW. In addition, the mount manager client fills in the NameLength member of the [**MOUNTDEV_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountdev_name) structure.

## Remarks

As a best practice, the implementer must not thread-synchronize and must not make blocking and/or Interprocess Communication (IPC) function calls.

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTDEV_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountdev_name)