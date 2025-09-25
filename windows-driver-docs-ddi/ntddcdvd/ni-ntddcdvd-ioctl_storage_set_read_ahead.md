# IOCTL_STORAGE_SET_READ_AHEAD IOCTL

## Description

Causes the device to skip to the given target address when the device reaches a certain trigger address during read-ahead caching.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [STORAGE_SET_READ_AHEAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_storage_set_read_ahead) structure that indicates the trigger and target addresses.

### Input buffer length

The length of a [STORAGE_SET_READ_AHEAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_storage_set_read_ahead) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS.

## See also

[STORAGE_SET_READ_AHEAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_storage_set_read_ahead)