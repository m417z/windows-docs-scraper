# DeviceDsmNumberOfDataSetRanges function

## Description

The **DeviceDsmNumberOfDataSetRanges** function gets the number of data set ranges in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

## Parameters

### `Input`

Pointer to a [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure.

## Return value

**DeviceDsmNumberOfDataSetRanges** returns the number of data set ranges in the payload. Each range is **sizeof**([DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range)).

## Remarks

See [Data Set Management](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for details on how to process a DSM.

## See also

[Data Set Management](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)