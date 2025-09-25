# _DEVICE_DSM_DEFINITION structure

## Description

The DEVICE_DSM_DEFINITION structure contains the properties for a data set management (DSM) action.

## Members

### `Action`

**DeviceDsmDefinition_*Xxx*** value that specifies the action to be performed. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for a list of action values and their associated definition values. These values are defined in *ntddstor.h*.

### `SingleRange`

Specifies whether the DSM action supports only a single range at a time. If the DSM action is to be performed on the entire data set range, the flag DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE is set.

### `ParameterBlockAlignment`

The alignment for the parameter block within the payload of the [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

### `ParameterBlockLength`

The length, in bytes, of the parameter block within the payload of the IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES request. The parameter block will follow the [DSM_DEVICE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure. If **ParameterBlockLength** is set to zero, then the parameter block does not exist.

### `HasOutput`

Set TRUE if the action specified in the **Action** member will return output; otherwise, set this to FALSE.

### `OutputBlockAlignment`

The alignment for the output block within the payload of the IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES request.

### `OutputBlockLength`

Specifies the length, in bytes, of the output block within the payload of the IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES request. The output block follows the DSM_DEVICE_OUTPUT structure. If **OutputBlockLength** is set to zero, then the output block does not exist.

## Remarks

Each DSM action has a definition associated with it. For example, **DeviceDsmAction_Trim** has **DeviceDsmDefinition_Trim** as its associated definition. The DSM sender or handler allocates and initializes the DEVICE_DSM_DEFINITION structure with the appropriate definition. They then pass the pointer to this structure to all DSM-related functions that need it.

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for information on how a DSM is processed.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DSM_DEVICE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)