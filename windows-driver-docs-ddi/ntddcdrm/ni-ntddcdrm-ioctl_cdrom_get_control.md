# IOCTL_CDROM_GET_CONTROL IOCTL

## Description

This IOCTL request is obsolete. Do not use.

Determines the current audio playback mode.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [CDROM_AUDIO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_audio_control) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**(CDROM_AUDIO_CONTROL).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL, STATUS_DEVICE_NOT_READY, STATUS_IO_DEVICE_ERROR, STATUS_IO_TIMEOUT, STATUS_INSUFFICIENT_RESOURCES, STATUS_VERIFY_REQUIRED, or STATUS_INVALID_DEVICE_REQUEST.

## See also

[CDROM_AUDIO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_audio_control)