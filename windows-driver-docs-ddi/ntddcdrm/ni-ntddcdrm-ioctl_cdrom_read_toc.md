# IOCTL_CDROM_READ_TOC IOCTL

## Description

Returns the table of contents of the media. Obsolete, beginning with Windows Vista.

## Parameters

### Major code

### Input buffer

Input buffer.

### Input buffer length

*Parameters.DeviceIoControl.OutputBufferLength* in the I/O stack location indicates the size, in bytes, of the buffer, which must be greater than or equal to **sizeof**(CDROM_TOC).

### Output buffer

The driver returns the [CDROM_TOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc) data in the buffer at *Irp->AssociatedIrp.SystemBuffer*.

### Output buffer length

Length of a [CDROM_TOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL, STATUS_NO_MEDIA_IN_DEVICE, STATUS_DEVICE_NOT_READY, STATUS_IO_TIMEOUT, STATUS_IO_DEVICE_ERROR, STATUS_DEVICE_BUSY, or STATUS_VERIFY_REQUIRED.

## Remarks

Beginning with Windows Vista, CDROM class drivers do not use this IOCTL. Prior to Windows Vista, this IOCTL was used for audio playback on older CD-ROM drives that supported direct audio output in hardware.

Client applications should use the *Media Control Interface (MCI) API* rather than issuing this IOCTL.

## See also

[CDROM_TOC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc)