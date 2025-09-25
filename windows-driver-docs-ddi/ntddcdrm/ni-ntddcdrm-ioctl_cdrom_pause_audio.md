# IOCTL_CDROM_PAUSE_AUDIO IOCTL

## Description

Suspends audio play. Obsolete, beginning with Windows Vista.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST if audio is not currently playing, STATUS_IO_DEVICE_ERROR, STATUS_NO_MEDIA_IN_DEVICE, STATUS_DEVICE_NOT_READY, STATUS_IO_TIME_OUT, or STATUS_VERIFY_REQUIRED.

## Remarks

Beginning with Windows Vista, CDROM class drivers do not use this IOCTL. Prior to Windows Vista, this IOCTL was used for audio playback on older CD-ROM drives that supported direct audio output in hardware.

Client applications should use the *Media Control Interface (MCI) API* rather than issuing this IOCTL.