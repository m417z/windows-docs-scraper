# IOCTL_CDROM_READ_Q_CHANNEL IOCTL

## Description

Returns the current position, media catalog, or ISRC track data. Reading the current position is obsolete, beginning with Windows Vista.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [CDROM_SUB_Q_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_sub_q_data_format) structure with the **Format** member set to one of the following:

IOCTL_CDROM_CURRENT_POSITION

IOCTL_CDROM_MEDIA_CATALOG

IOCTL_CDROM_TRACK_ISRC

If **Format** is set to IOCTL_CDROM_TRACK_ISRC, **Track** must be set to the track for which ISRC data is requested.

### Input buffer length

Length of a **Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**(SUB_Q_CHANNEL_DATA).

.

### Output buffer

The driver returns the [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data) information in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

Length of a [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL, STATUS_IO_DEVICE_ERROR, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_DEVICE_REQUEST, STATUS_NO_MEDIA_IN_DEVICE, STATUS_DEVICE_NOT_READY, STATUS_IO_TIME_OUT, or STATUS_VERIFY_REQUIRED.

## Remarks

Beginning with Windows Vista, CDROM class drivers do not use this IOCTL with the format member set to IOCTL_CDROM_CURRENT_POSITION. Prior to Windows Vista, this IOCTL was used for audio playback on older CD-ROM drives that supported direct audio output in hardware.

Client applications should use the *Media Control Interface (MCI) API* rather than issuing this IOCTL.

## See also

[SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data)