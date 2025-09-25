# DEVICE_DATA_SET_RANGE structure

## Description

Provides data set range information for use with the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `StartingOffset`

Starting offset of the data set range in bytes, relative to the start of the volume. Must align to disk
logical sector size.

### `LengthInBytes`

Length of the data set range, in bytes. Must be a multiple of disk logical sector size.

## See also

[DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)