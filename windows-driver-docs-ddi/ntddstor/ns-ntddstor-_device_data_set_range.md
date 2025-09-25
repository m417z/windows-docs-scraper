# _DEVICE_DATA_SET_RANGE structure

## Description

The **DEVICE_DSM_RANGE** (or DEVICE_DATA_SET_RANGE) structure specifies a data set range for the attributes for a device.

A block of data set ranges, if any, is specified in the payload of an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

## Members

### `StartingOffset`

Contains the starting offset, in bytes, of the data set range. The offset value must be block aligned.

### `LengthInBytes`

Contains the length, in bytes, of the data set range. The length value must be block aligned.

## Remarks

See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for more information about processing DSM actions that involve data set ranges.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)