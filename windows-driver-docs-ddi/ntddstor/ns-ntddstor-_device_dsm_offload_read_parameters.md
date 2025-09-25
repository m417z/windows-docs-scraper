# _DEVICE_DSM_OFFLOAD_READ_PARAMETERS structure

## Description

The DEVICE_DSM_OFFLOAD_READ_PARAMETERS structure specifies the parameters for an offload read action related to the data-set attributes for a device.

## Members

### `Flags`

Not used. Set to 0.

### `TimeToLive`

The duration, in milliseconds, for which the requested data ranges should remain valid.

### `Reserved`

Reserved.

## Remarks

This structure is used in an offload read action for an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request. The **Action** member of the [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure is set to **DeviceDsmAction_OffloadRead**.

The **ParameterBlockOffset** and **ParameterBlockLength** members of [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure are set to the location and length of the DEVICE_DSM_OFFLOAD_READ_PARAMETERS structure in the input buffer of the [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

The **DataSetRangesOffset** and **DataSetRangesLength** members of DEVICE_DSM_INPUT specify the [DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range) structures for the extents of the offload read.

See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for more details about this action.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_offload_write_parameters)

[DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range)