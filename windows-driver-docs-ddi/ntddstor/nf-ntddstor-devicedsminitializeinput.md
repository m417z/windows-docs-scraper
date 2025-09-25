# DeviceDsmInitializeInput function

## Description

The **DeviceDsmInitializeInput** function initializes the [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure and parameter block, if any, of a data set management (DSM) operation.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the action.

### `Input`

Pointer to a caller-allocated [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) input structure.

### `InputLength`

The length, in bytes, of the entire input buffer for the [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

### `Flags`

Flags for global control actions for the input. This value can be one of the DEVICE_DSM_FLAG_*XXX* values defined in *ntddstor.h*.

### `Parameters`

Parameters for initializing the parameter block of the input structure. The format of the parameter block depends on the action defined by *Definition*. See [DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions) for a list of actions and their parameter block formats.

### `ParameterBlockLength`

The length, in bytes, of the parameter block. If the action defined by *Definition* does not have parameters, *ParameterBlockLength* is set to zero.

## Remarks

To add a data set range to the input operation, call [**DeviceDsmAddDataSetRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/nf-ntddstor-devicedsmadddatasetrange).

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for information on how to set up and process a DSM action.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[**DeviceDsmAddDataSetRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/nf-ntddstor-devicedsmadddatasetrange)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)