# GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST structure

## Description

The GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST structure describes the internal status data being requested through [IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log).

## Members

### `Version`

Version of this structure. Set to **sizeof**(GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST).

### `Size`

Total size in bytes of this structure. Set to **sizeof**(GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST).

### `RequestDataType`

A [DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-device_internal_status_data_request_type) enumeration that identifies the data type being requested.

### `RequestDataSet`

A [DEVICE_INTERNAL_STATUS_DATA_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-device_internal_status_data_set) enumeration that identifies the device status data set.

## Remarks

GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST is the input buffer for [IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log).

## See also

[DEVICE_INTERNAL_STATUS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-device_internal_status_data)

[DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-device_internal_status_data_request_type)

[DEVICE_INTERNAL_STATUS_DATA_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-device_internal_status_data_set)

[IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log)