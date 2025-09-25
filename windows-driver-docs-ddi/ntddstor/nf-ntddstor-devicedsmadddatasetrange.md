# DeviceDsmAddDataSetRange function

## Description

The **DeviceDsmAddDataSetRange** function adds a data set range to the system buffer for an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

## Parameters

### `Input`

Pointer to the [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) structure to which to add the data set range.

### `InputLength`

The length, in bytes, of the entire payload of the IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES request.

### `Offset`

The offset from the start of the DEVICE_DSM_INPUT structure at which the data set range starts, in bytes.

### `Length`

The length, in bytes, of the data set range.

## Return value

Returns TRUE if the data set range was successfully added, or FALSE otherwise.

## Remarks

If the DSM has range data, call **DeviceDsmAddDataSetRange** for each range to add it to the system buffer. See [Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview) for the layout of the system buffer for an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request.

## See also

[Data Set Management Overview](https://learn.microsoft.com/windows-hardware/drivers/storage/data-set-management-overview)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[DEVICE_DSM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_data_set_range)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)