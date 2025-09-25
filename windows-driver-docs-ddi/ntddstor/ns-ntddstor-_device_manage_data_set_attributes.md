# _DEVICE_MANAGE_DATA_SET_ATTRIBUTES structure

## Description

The **DEVICE_DSM_INPUT** (or DEVICE_MANAGE_DATA_SET_ATTRIBUTES) structure specifies a management action for the data-set attributes for a device.

## Members

### `Size`

Size of the DEVICE_DSM_INPUT structure, in bytes. The value of this member will change as members are added to the structure.

### `Action`

A DEVICE_DSM_ACTION value that specifies the action to be performed. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for a list of action values and descriptions.

If the **DeviceDsmActionFlag_NonDestructive** flag (most significant bit) is set in **Action**, the specified action is nondestructive. For nondestructive actions, the driver can safely forward the [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request to the next lower driver in the stack even if the driver does not handle the specified action. If the driver does handle the DSM, it should perform the normal processing of the data set ranges block that is specified by the **DataSetRangesOffset** and **DataSetRangesLength** members before forwarding the IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES request to the next lower driver.

### `Flags`

These flags are global to all control actions. This member can be set to one of the following flags:

| Flag Value | Meaning |
| ---------- | ------- |
| DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE | The control action is specified for the entire block of data set ranges. If this flag is set, the **DataSetRangesOffset** and **DataSetRangesLength** members must be set to zero. |

### `ParameterBlockOffset`

Specifies the start of the parameter block within the payload of the [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request. The format of the parameter block depends on the value of the **Action** member. For more information regarding parameter block format, see [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions). **Note**: The offset of the parameter block must be aligned on the address boundary of the corresponding parameter.

If **ParameterBlockOffset** is set to zero, then the parameter block does not exist.

### `ParameterBlockLength`

Specifies the length, in bytes, of the parameter block within the payload of the IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES request.

If **ParameterBlockLength** is set to zero, then the parameter block does not exist.

### `DataSetRangesOffset`

Specifies the start of the block of data set ranges within the payload of the IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES request. This block consists of one or more contiguous entries that are formatted as [DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range) structures. **Note**: The offset of the data set range block must be aligned on the address boundary of the DEVICE_DSM_RANGE structure.

If set to zero, then the block of data set ranges does not exist.

### `DataSetRangesLength`

Specifies the length, in bytes, of the block of data set ranges within the payload of the IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES request. If **DataSetRangesLength** is set to zero, the block of data set ranges does not exist.

## Remarks

For more information on the format of the payload for an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request, see [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview). The total size of the buffer should be at least ```sizeof(DEVICE_DSM_INPUT) + ParameterBlockLength + DataSetRangesLength```.

The block of data set ranges is specified by the **DataSetRangesOffset** and **DataSetRangesLength** members. If this block exists, it contains contiguous [DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range) structures.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)