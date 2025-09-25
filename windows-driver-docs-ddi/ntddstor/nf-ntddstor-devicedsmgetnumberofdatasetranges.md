# DeviceDsmGetNumberOfDataSetRanges function

## Description

The **DeviceDsmGetNumberOfDataSetRanges** function gets the number of data set ranges required for the specified data set management (DSM) operation.

## Parameters

### `Definition`

Pointer to a [DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition) structure that defines the operation.

### `InputLength`

The length, in bytes, of the entire input buffer.

### `ParameterBlockLength`

The length, in bytes, of a parameter block.

## Return value

**DeviceDsmGetNumberOfDataSetRanges** returns the number of data set ranges required for the specified operation. Each range is **sizeof**([DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range)).

## Remarks

See [Data Set Management](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for details on how to process a DSM.

## See also

[Data Set Management](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_DEFINITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_dsm_definition)

[DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)