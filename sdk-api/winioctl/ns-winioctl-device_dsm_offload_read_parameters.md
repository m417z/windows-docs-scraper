# DEVICE_DSM_OFFLOAD_READ_PARAMETERS structure

## Description

Contains parameters for the **DeviceDsmAction_OffloadRead** action for the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `Flags`

Set to 0.

### `TimeToLive`

The time to live (TTL) for the token, in milliseconds.

### `Reserved`

Set to 0.

## See also

[DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)

[STORAGE_OFFLOAD_READ_OUTPUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_offload_read_output)