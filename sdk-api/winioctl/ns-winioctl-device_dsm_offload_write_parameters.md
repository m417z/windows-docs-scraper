# DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS structure

## Description

Specifies parameters for the offload write operation. An offload write operation is
initiated by specifying **DeviceDsmAction_OffloadWrite** in the
**Action** member of the
[DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)
structure passed in a
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `Flags`

Set to 0.

### `Reserved`

Reserved.

### `TokenOffset`

The starting offset to copy from the range bound to the token

### `Token`

[STORAGE_OFFLOAD_TOKEN](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_offload_token) structure containing
the token returned from the offload read operation.

## See also

[DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)

[STORAGE_OFFLOAD_TOKEN](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_offload_token)