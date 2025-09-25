# DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE enumeration

## Description

The **DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE** enum identifies the internal status data type being queried.

## Constants

### `DeviceInternalStatusDataRequestTypeUndefined`

Reserved; do not use.

### `DeviceCurrentInternalStatusDataHeader`

Query the device's internal status data header. The data header size is always 512 bytes. Refer to the SCSI specification for more details about the header format.

### `DeviceCurrentInternalStatusData`

Query the device's internal status data. The data block size is always a multiple of 512 bytes.

### `DeviceSavedInternalStatusDataHeader`

Query the device's saved internal status data header. The data header size is always 512 bytes. Refer to the SCSI specification for more details about the header format.

### `DeviceSavedInternalStatusData`

Query the device's saved internal status data. The data block size is always a multiple of 512 bytes.

## Remarks

DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE is a member of the [GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-get_device_internal_status_data_request) structure, which contains all information about the internal status data being requested through [IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log).

The [DEVICE_INTERNAL_STATUS_DATA_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-device_internal_status_data_set) enum identifies the data set associated with the data request type.

## See also

[DEVICE_INTERNAL_STATUS_DATA_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-device_internal_status_data_set)

[GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-get_device_internal_status_data_request)

[IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log)