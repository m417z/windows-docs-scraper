# STORAGE_TEMPERATURE_INFO structure

## Description

Describes device temperature data. Returned as part of [STORAGE_TEMPERATURE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_temperature_data_descriptor) when querying for temperature data with an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) request.

## Members

### `Index`

Identifies the instance of temperature information. Starts from 0. Index 0 may indicate a composite value.

### `Temperature`

A signed value that indicates the current temperature, in degrees Celsius.

### `OverThreshold`

A signed value that specifies the maximum temperature within the desired threshold, in degrees Celsius.

### `UnderThreshold`

A signed value that specifies the minimum temperature within the desired threshold, in degrees Celsius.

### `OverThresholdChangable`

Indicates if *OverThreshold* can be changed by using [IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_set_temperature_threshold).

### `UnderThresholdChangable`

Indicates if *UnderThreshold* can be changed by using [IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_set_temperature_threshold).

### `EventGenerated`

Indicates if a notification will be generated when the current temperature crosses a threshold.

### `Reserved0`

Reserved for future use.

### `Reserved1`

Reserved for future use.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_set_temperature_threshold)

[STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_property_id)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query)