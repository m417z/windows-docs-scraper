# IOCTL_STORAGE_LOAD_MEDIA IOCTL

## Description

Causes media to be loaded in a device that the caller has opened for read or write access. If read or write access to the device is not necessary, the caller can improve performance by opening the device with FILE_READ_ATTRIBUTES and issuing an [IOCTL_STORAGE_LOAD_MEDIA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_load_media2) request instead.

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

[IOCTL_STORAGE_LOAD_MEDIA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_load_media2)