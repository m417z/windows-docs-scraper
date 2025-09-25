# DeviceDsmGetInputLength function

## Description

The **DeviceDsmGetInputLength** function calculates the total number of bytes in a data set management (DSM) input operation.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the action.

### `ParameterBlockLength`

The length, in bytes, of the input operation's parameter block. If the input operation has no parameters, *ParameterBlockLength* is set to zero.

### `NumberOfDataSetRanges`

The number of data set ranges associated with the input operation. If the input operation has no data set ranges, *NumberOfDataSetRanges* is set to zero.

## Return value

**DeviceDsmGetInputLength** returns the total number of bytes required for the input operation: the length of the [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure, plus the length of the parameter block (if any), plus the length of all data set ranges (if any).

## Remarks

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for information on how to set up and process a DSM action.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)