# IOCTL_STORAGE_CHECK_VERIFY2 IOCTL

## Description

Determines whether the media has changed on a removable-media device - the caller has opened with FILE_READ_ATTRIBUTES. Because no file system is mounted when a device is opened in this way, this request can be processed much more quickly than an IOCTL_STORAGE_CHECK_VERIFY request.

## Parameters

### Major code

### Input buffer

Input is identical to the input for [IOCTL_STORAGE_CHECK_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_check_verify).

### Input buffer length

Input length is identical to input length for [IOCTL_STORAGE_CHECK_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_check_verify).

### Output buffer

Output is identical to the output for [IOCTL_STORAGE_CHECK_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_check_verify).

### Output buffer length

Output length is identical to output length for [IOCTL_STORAGE_CHECK_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_check_verify).

### Input/output buffer

### Input/output buffer length

### Status block

I/O status is identical to the I/O status for [IOCTL_STORAGE_CHECK_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_check_verify).

## See also

[IOCTL_STORAGE_CHECK_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_check_verify)