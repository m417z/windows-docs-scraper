# IOCTL_CDROM_FIND_NEW_DEVICES IOCTL

## Description

In Microsoft Windows 2000 and later operating systems, this IOCTL is replaced by [IOCTL_STORAGE_FIND_NEW_DEVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_find_new_devices). The only difference between the two IOCTLs is the base value.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).