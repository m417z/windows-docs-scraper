# _DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS structure

## Description

The DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS structure specifies the parameters for an offload write action related to the data-set attributes for a device.

## Members

### `Flags`

Not used.

### `Reserved`

Reserved.

### `TokenOffset`

The offset, in bytes, within the data block specified by **Token** to begin writing from.

### `Token`

The unique identifier of the data block to write from.

## Remarks

This structure is used in an offload write action for an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request. The **Action** member of the [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure is set to **DeviceDsmAction_OffloadWrite**.

The **ParameterBlockOffset** and **ParameterBlockLength** members of [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) are set to the location and length of the DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS structure in the system buffer of the [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

The **DataSetRangesOffset** and **DataSetRangesLength** members of DEVICE_DSM_INPUT specify the [DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range) structures for the extents of the offload write.

See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for more details about this action.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[DEVICE_DSM_OFFLOAD_READ_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_offload_read_parameters)

[DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)