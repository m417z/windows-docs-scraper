# DEVICE_INTERNAL_STATUS_DATA_SET enumeration

## Description

DEVICE_INTERNAL_STATUS_DATA_SET identifies the device internal status data set to query.

## Constants

### `DeviceStatusDataSetUndefined`

Reserved; do not use.

### `DeviceStatusDataSet1`

This field corresponds to data set 1.

### `DeviceStatusDataSet2`

This field corresponds to data set 2.

### `DeviceStatusDataSet3`

This field corresponds to data set 3.

### `DeviceStatusDataSet4`

This field corresponds to data set 4.

### `DeviceStatusDataSetMax`

Maximum data set number.

## Remarks

DEVICE_INTERNAL_STATUS_DATA_SET is a member of the [GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-get_device_internal_status_data_request) structure, which contains all information about the internal status data being requested through [IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log).

The [DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-device_internal_status_data_set) enum identifies the data request type associated with the data set identified by this enum.

See the SCSI specification for details.

## See also

[DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-device_internal_status_data_set)

[GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-get_device_internal_status_data_request)

[IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log)