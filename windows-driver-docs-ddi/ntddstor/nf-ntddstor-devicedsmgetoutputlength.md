# DeviceDsmGetOutputLength function

## Description

The **DeviceDsmGetOutputLength** function gets the length, in bytes, of the output buffer for a data set management (DSM) operation.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the DSM operation.

### `OutputBlockLength`

The length, in bytes, of the output block.

## Return value

**DeviceDsmGetOutputLength** returns the total number of bytes in the output: the length of a [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) structure plus the length of the output block, if any. It returns zero if the operation does not have output.

## Remarks

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for information on how to set up and process a DSM action.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition)

[DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output)