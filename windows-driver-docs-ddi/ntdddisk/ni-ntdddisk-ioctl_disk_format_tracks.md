# IOCTL_DISK_FORMAT_TRACKS IOCTL

## Description

Formats the specified set of contiguous tracks on the disk.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [FORMAT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_format_parameters) data. **Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer.

### Output buffer

The device driver returns an array of BAD_TRACK_NUMBER values to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

Length of the buffer.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size of the returned bad-track array when the **Status** field is set to STATUS_SUCCESS. Otherwise, the **Information** field is zero and the **Status** field possibly can be set to STATUS_INVALID_PARAMETER or STATUS_MEDIA_WRITE_PROTECTED if the media is removable.

## See also

[FORMAT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_format_parameters)