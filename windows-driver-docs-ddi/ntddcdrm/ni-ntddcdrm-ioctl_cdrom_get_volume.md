# IOCTL_CDROM_GET_VOLUME IOCTL

## Description

Determines the current volume for each of its device's audio ports. Obsolete, beginning with Windows Vista.

## Parameters

### Major code

### Input buffer

Input buffer.

### Input buffer length

*Parameters.DeviceIoControl.OutputBufferLength* in the I/O stack location indicates the size, in bytes, of the buffer, which must be greater than or equal to  **sizeof**(VOLUME_CONTROL).

### Output buffer

The driver returns the [VOLUME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_volume_control) data in the buffer at *Irp->AssociatedIrp.SystemBuffer*.

### Output buffer length

Length of the [VOLUME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_volume_control) data.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(VOLUME_CONTROL) when the **Status** field is set to STATUS_SUCCESS. Otherwise, the **Information** field is set to zero, and the **Status** field possibly can be set to STATUS_BUFFER_TOO_SMALL, STATUS_DEVICE_NOT_READY, STATUS_IO_DEVICE_ERROR, STATUS_VERIFY_REQUIRED, or STATUS_IO_TIMEOUT.

## Remarks

Beginning with Windows Vista, CDROM class drivers do not use this IOCTL. Prior to Windows Vista, this IOCTL was used for audio playback on older CD-ROM drives that supported direct audio output in hardware.

Client applications should use the *Media Control Interface (MCI) API* rather than issuing this IOCTL.

## See also

[VOLUME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_volume_control)