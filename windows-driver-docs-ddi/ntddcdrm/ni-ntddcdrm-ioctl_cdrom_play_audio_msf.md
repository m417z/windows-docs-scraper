# IOCTL_CDROM_PLAY_AUDIO_MSF IOCTL

## Description

Plays the specified range of the media. Obsolete, beginning with Windows Vista.

## Parameters

### Major code

### Input buffer

The [CDROM_PLAY_AUDIO_MSF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_play_audio_msf) structure in the buffer at *Irp->AssociatedIrp.System* contains the starting and ending MSF values.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* in the I/O stack location indicates the size, in bytes, of the buffer, which must be greater than or equal to  **sizeof**(CDROM_PLAY_AUDIO_MSF).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_BUFFER_TOO_SMALL, STATUS_DEVICE_NOT_READY, STATUS_IO_DEVICE_ERROR, STATUS_IO_TIME_OUT, or STATUS_VERIFY_REQUIRED.

## Remarks

Beginning with Windows Vista, CDROM class drivers do not use this IOCTL. Prior to Windows Vista, this IOCTL was used for audio playback on older CD-ROM drives that supported direct audio output in hardware.

Client applications should use the *Media Control Interface (MCI) API* rather than issuing this IOCTL.

## See also

[CDROM_PLAY_AUDIO_MSF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_play_audio_msf)