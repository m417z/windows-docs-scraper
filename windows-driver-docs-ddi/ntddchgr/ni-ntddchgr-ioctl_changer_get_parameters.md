# IOCTL_CHANGER_GET_PARAMETERS IOCTL

## Description

Returns the parameters of the device.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(GET_CHANGER_PARAMETERS).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH or STATUS_INSUFFICIENT_RESOURCES.

## See also

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)