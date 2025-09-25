# STORAGE_OFFLOAD_READ_OUTPUT structure

## Description

Output structure for the **DeviceDsmAction_OffloadRead** action of the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `OffloadReadFlags`

Output flags.

| Value | Meaning |
| --- | --- |
| **STORAGE_OFFLOAD_READ_RANGE_TRUNCATED**<br><br>0x0001 | The ranges represented by the token is smaller than the ranges specified in the [DEVICE_DATA_SET_RANGE](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-device_data_set_range) structures passed in the [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes) control code input buffer. In other words the **LengthProtected** member is less than the sum of all of the **LengthInBytes** members of the **DEVICE_DATA_SET_RANGE** structures passed. |

### `Reserved`

Reserved.

### `LengthProtected`

The total length of the snapshot represented by the token.

### `TokenLength`

Length of the token in bytes.

### `Token`

A [STORAGE_OFFLOAD_TOKEN](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_offload_token) containing the
token created.

## See also

[DEVICE_DSM_OFFLOAD_READ_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_dsm_offload_read_parameters)

[DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes_output)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)

[STORAGE_OFFLOAD_TOKEN](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_offload_token)