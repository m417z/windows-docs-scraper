## Description

**IOCTL_MOUNTDEV_QUERY_UNIQUE_ID** retrieves a unique identifier for a device or volume.

Mount manager clients must support this IOCTL. Upon receiving this IOCTL, the mount manager client must provide a counted byte string identifier that is unique to the client (that is, the device or the volume).

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The device class or volume driver returns the [**MOUNTDEV_UNIQUE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ns-mountdev-_mountdev_unique_id) structure in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be greater than or equal to ```sizeof(MOUNTDEV_UNIQUE_ID)```.

### Input/output buffer

N/A

### Input/output buffer length

N/A

### Status block

The **Information** field is set to FIELD_OFFSET([**MOUNTDEV_UNIQUE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ns-mountdev-_mountdev_unique_id), UniqueId) + output->UniqueIdLength; or alternatively to sizeof(USHORT) + output->UniqueIdLength, where output points to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

## Remarks

The implementer of this function must not thread synchronize and must not make blocking and/or Interprocess Communication (IPC) function calls.

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**MOUNTDEV_UNIQUE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ns-mountdev-_mountdev_unique_id)