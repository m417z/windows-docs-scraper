# IOCTL_CDROM_SET_VOLUME IOCTL

## Description

Resets the volume for its device's audio ports. Obsolete, beginning with Windows Vista.

## Parameters

### Major code

### Input buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* contains the [VOLUME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_volume_control) value or values to be set.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* in the I/O stack location indicates the size, in bytes, of the buffer, which must be greater than or equal to **sizeof**(VOLUME_CONTROL).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL, STATUS_DEVICE_NOT_READY, STATUS_IO_TIMEOUT, STATUS_IO_DEVICE_ERROR, STATUS_VERIFY_REQUIRED, or STATUS_INVALID_DEVICE_REQUEST.

## Remarks

Beginning with Windows Vista, CDROM class drivers do not use this IOCTL. Prior to Windows Vista, this IOCTL was used for audio playback on older CD-ROM drives that supported direct audio output in hardware.

Client applications should use the *Media Control Interface (MCI) API* rather than issuing this IOCTL.

## See also

[VOLUME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_volume_control)