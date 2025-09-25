# IOCTL_STORAGE_CHECK_VERIFY IOCTL

## Description

Determines whether the media has changed on a removable-media device that the caller has opened for read or write access. If read or write access to the device is not necessary, the caller can improve performance by opening the device with FILE_READ_ATTRIBUTES and issuing an[IOCTL_STORAGE_CHECK_VERIFY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_check_verify2) request instead.

For more information, see [Supporting Removable Media](https://learn.microsoft.com/windows-hardware/drivers/kernel/supporting-removable-media).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

Optionally, for disk and CD-ROM devices, **Irp->AssociatedIrp.SystemBuffer** points to a buffer to receive the media change count. The driver fills this buffer only if **Parameters.DeviceIoControl.OutputBufferLength** was nonzero and the return value is STATUS_SUCCESS. The media change count is a ULONG indicating how many times the media has changed since the driver started.

Otherwise, this request has no output.

### Output buffer length

Optionally, for disk and CD-ROM devices, **Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of a buffer, which must be >= **sizeof**(ULONG). This field is zero if the optional buffer is not specified.

Otherwise, this request has no input.

### Input/output buffer

### Input/output buffer length

### Status block

If a disk or CD-ROM driver has no indication that the media has changed, the driver sets the **Status** field to STATUS_SUCCESS. In addition, if the optional media change buffer was specified, the driver returns the media change count in the buffer at **Irp->AssociatedIrp.SystemBuffer** and sets the **Information** field to **sizeof**(ULONG). If the optional media change buffer was not specified, the driver sets **Information** to zero.

If the driver detects that the media has changed and the volume is mounted (VPB_MOUNTED is set in the VPB), it must:

1. Set **Information** to zero.
2. Set **Status** to STATUS_VERIFY_REQUIRED.
3. Set the DO_VERIFY_VOLUME flag in the **DeviceObject.**
4. Call **IoCompleteRequest** with the input IRP.

If the driver detects that the media has changed, but the volume is not mounted, the driver must not set the DO_VERIFY_VOLUME bit. Instead, it should do the following:

1. Set **Status** to STATUS_IO_DEVICE_ERROR.
2. Set **Information** to zero.
3. Call **IoCompleteRequest** with the IRP.

If the driver detects an error such as STATUS_BUFFER_TOO_SMALL, STATUS_INSUFFICIENT_RESOURCES, or a device error, it sets **Information** to zero and sets the appropriate error value in the **Status** field.

For a tape driver, the **Information** field is set to zero and the **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_VERIFY_REQUIRED.

## See also

[IOCTL_STORAGE_CHECK_VERIFY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_check_verify2)