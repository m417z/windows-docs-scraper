## Description

This IOCTL offloads the erasure process to the storage device.

## Parameters

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

There is no guarantee as to the successful deletion or recoverability of the data on the storage device after command completion. This IOCTL is limited to data disks in regular Windows. In WinPE, this IOCTL is supported for both boot and data disks.

There may be cached data from the storage device in the system. To ensure there is no cached data from the storage device before erasure, call FSCTL_LOCK_VOLUME. The operating system does not ensure all outstanding requests to the storage device are completed before issuing the erasure command to the device.

## See also