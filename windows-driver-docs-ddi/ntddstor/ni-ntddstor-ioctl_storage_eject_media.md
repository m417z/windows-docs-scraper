# IOCTL_STORAGE_EJECT_MEDIA IOCTL

## Description

Causes the device to eject the media if the device supports ejection capabilities.

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

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_NO_MEDIA_IN_DEVICE or STATUS_INVALID_DEVICE_REQUEST.

## See also

[IOCTL_STORAGE_EJECTION_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_ejection_control)