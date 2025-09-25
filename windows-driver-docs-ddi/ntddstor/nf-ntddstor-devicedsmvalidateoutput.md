# DeviceDsmValidateOutput function

## Description

The **DeviceDsmValidateOutput** function validates the output for a data set management (DSM) operation.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the operation.

### `Output`

Pointer to the [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) structure of the operation.

### `OutputLength`

The length, in bytes, of the entire output buffer.

## Return value

Returns TRUE if the output is valid, or FALSE otherwise.

## Remarks

The output is returned in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request. Before extracting the output, the caller should first call **DeviceDsmValidateOutput** to ensure that the output is valid based on the operation's *Definition* and *Output* (whose **Action** members must match), including the DEVICE_DSM_OUTPUT structure that *Output* points to, and the output block, if any, that follows the DEVICE_DSM_OUTPUT structure.

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for more details on handling a DSM.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output)