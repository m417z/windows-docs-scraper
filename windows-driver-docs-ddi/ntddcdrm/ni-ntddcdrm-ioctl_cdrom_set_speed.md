# IOCTL_CDROM_SET_SPEED IOCTL

## Description

Sets the spindle speed of the CD-ROM drive.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains either a [CDROM_SET_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_set_speed) structure or a [CDROM_SET_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_set_streaming) structure. These two structures have the same first member: an [CDROM_SPEED_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_speed_request) enumeration value. Caller uses this enumeration value to specify which of these two structures is in the input buffer.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, if the operation succeeds, to STATUS_INFO_LENGTH_MISMATCH (ERROR_BAD_LENGTH) if the input buffer was too small, to STATUS_INVALID_DEVICE_REQUEST (ERROR_INVALID_FUNCTION), if the device does not support the request, or the device is not a Mount Ranier reWriteable (MRW)-compliant device, and to STATUS_INVALID_PARAMETER (ERROR_INVALID_PARAMETER, if the indicated request type is invalid.

## Remarks

For an explanation of function and purpose of this request, see [CD-ROM Set Speed](https://learn.microsoft.com/windows-hardware/drivers/storage/cd-rom-set-speed).