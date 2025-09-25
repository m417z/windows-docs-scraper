# IOCTL_DISK_IS_WRITABLE IOCTL

## Description

Determines whether a disk is writable.

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

The **Information** field is set to zero. The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES, STATUS_IO_DEVICE_ERROR, or STATUS_MEDIA_WRITE_PROTECTED.