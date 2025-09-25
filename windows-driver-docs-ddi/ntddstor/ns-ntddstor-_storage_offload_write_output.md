# _STORAGE_OFFLOAD_WRITE_OUTPUT structure

## Description

The STORAGE_OFFLOAD_WRITE_OUTPUT structure is the output of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) control code request when the **Action** member of [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) is set to **DeviceDsmAction_OffloadWrite**.

## Members

### `OffloadWriteFlags`

Flags indicating the result of the offload write operation. This is set to one of the following.

| Value | Meaning |
| ----- | ------- |
| STORAGE_OFFLOAD_WRITE_RANGE_TRUNCATED | The offload write was performed but the range written was truncated. |
| STORAGE_OFFLOAD_TOKEN_INVALID | The token provided for the offload write operation was invalid. |

### `Reserved`

Reserved.

### `LengthCopied`

Bytes copied for the write request in DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS.

## Remarks

On input, a token value in [DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_offload_write_parameters) uniquely identifies the data set ranges requested for writing in the DEVICE_DSM_INPUT structure. The STORAGE_OFFLOAD_WRITE_OUTPUT structure contains the results of the write operation.

The STORAGE_OFFLOAD_WRITE_OUTPUT structure is returned at the beginning of the system buffer.

## See also

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_offload_write_parameters)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)