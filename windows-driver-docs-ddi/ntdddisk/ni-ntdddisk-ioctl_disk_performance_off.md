# IOCTL_DISK_PERFORMANCE_OFF IOCTL

## Description

Disables the counters that were enabled by previous calls to [IOCTL_DISK_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_performance). This request is available in Windows XP and later operating systems. Caller must be running at IRQL = PASSIVE_LEVEL.

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

The **Information** member is set to zero. The **Status** member is set to STATUS_SUCCESS if the operation was successful. Otherwise, the **Status** member is set to the appropriate error code.

## See also

[IOCTL_DISK_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_performance)