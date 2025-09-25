# IOCTL_STORAGE_LOAD_MEDIA2 IOCTL

## Description

Causes media to be loaded in a device that the caller has opened with FILE_READ_ATTRIBUTES. Because no file system is mounted when a device is opened in this way, this request can be processed much more quickly than an [IOCTL_STORAGE_LOAD_MEDIA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_load_media) request.

Input, output, and I/O status block values for IOCTL_STORAGE_LOAD_MEDIA2 are identical to those for IOCTL_STORAGE_LOAD_MEDIA.

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

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_NO_MEDIA_IN_DEVICE, STATUS_BUFFER_TOO_SMALL, or STATUS_DEVICE_NOT_CONNECTED.

## See also

[IOCTL_STORAGE_LOAD_MEDIA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_load_media)