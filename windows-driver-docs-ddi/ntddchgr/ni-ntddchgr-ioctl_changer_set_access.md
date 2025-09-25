# IOCTL_CHANGER_SET_ACCESS IOCTL

## Description

Sets the state of the device's import/export port (IEport), door, or keypad.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_set_access) structure indicating the element and the operation to perform.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(CHANGER_SET_ACCESS).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes set. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_DEVICE_REQUEST, or STATUS_INVALID_PARAMETER.

## See also

[CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_set_access)

[ChangerSetAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetaccess)