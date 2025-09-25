# DeviceDsmValidateInput function

## Description

The **DeviceDsmValidateInput** function validates the input for a data set management (DSM) operation.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the operation.

### `Input`

Pointer to the [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure of the operation.

### `InputLength`

The length, in bytes, of the entire input buffer.

## Return value

Returns **TRUE** if the input is valid, or **FALSE** otherwise.

## Remarks

The input is passed in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request. Before processing the request, the handler should first call **DeviceDsmValidateInput** to ensure that the input is valid based on the operation's *Definition* and *Input* (whose **Action** members must match), including the DEVICE_DSM_INPUT structure that *Input* points to, and the parameter block and data set ranges, if any, that follow the DEVICE_DSM_INPUT structure.

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for more details on handling a DSM.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)