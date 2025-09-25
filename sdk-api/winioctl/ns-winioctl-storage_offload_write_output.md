# STORAGE_OFFLOAD_WRITE_OUTPUT structure

## Description

Output structure for the **DeviceDsmAction_OffloadWrite** action of the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `OffloadWriteFlags`

Out flags

| Value | Meaning |
| --- | --- |
| **STORAGE_OFFLOAD_WRITE_RANGE_TRUNCATED**<br><br>0x0001 | The range written is less than the range specified. |
| **STORAGE_OFFLOAD_TOKEN_INVALID**<br><br>0x0002 | The token specified is not valid. |

### `Reserved`

Reserved.

### `LengthCopied`

The length of the copied content.

## See also

[DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes_output)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)