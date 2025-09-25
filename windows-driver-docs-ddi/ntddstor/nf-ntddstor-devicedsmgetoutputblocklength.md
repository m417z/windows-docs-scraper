# DeviceDsmGetOutputBlockLength function

## Description

The **DeviceDsmGetOutputBlockLength** function gets the length, in bytes, of a data set management (DSM) output block.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the operation.

### `OutputLength`

The length, in bytes, of the entire output (the [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) output buffer plus the output block).

## Return value

Returns the length, in bytes, of the output block.

## Remarks

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for information on how to set up and process a DSM action.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition)

[DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output)