# IOCTL_DISK_FORMAT_TRACKS_EX IOCTL

## Description

Is similar to [IOCTL_DISK_FORMAT_TRACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_format_tracks), except that it allows the caller to specify several more parameters. The additional extended parameters are the format gap length, the number of sectors per track, and an array whose element size is equal to the number of sectors per track. This array represents the track layout.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [FORMAT_EX_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_format_ex_parameters) data.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer.

### Output buffer

The device driver returns an array of BAD_TRACK_NUMBER values to the buffer at **Irp->AssociatedIrp.SystemBuffer**. BAD_TRACK_NUMBER is currently defined as a WORD on 32-bit systems.

### Output buffer length

Length of the buffer.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets the **Status** field to STATUS_SUCCESS. Otherwise, the driver sets the **Status** field to STATUS_INVALID_PARAMETER if the input buffer length is < **sizeof**(FORMAT_EX_PARAMETERS) or if the format parameters supplied by the caller will not work on the drive to be formatted.

## See also

[FORMAT_EX_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_format_ex_parameters)

[IOCTL_DISK_FORMAT_TRACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_format_tracks)