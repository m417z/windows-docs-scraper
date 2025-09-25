# STORAGE_TEMPERATURE_THRESHOLD structure

## Description

This structure is used to set the over or under temperature threshold of a storage device (via [IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_set_temperature_threshold)).

## Members

### `Version`

The version of the structure.

### `Size`

The size of this structure. This should be set to sizeof(**STORAGE_TEMPERATURE_THRESHOLD**).

### `Flags`

Flags set for this request. The following are valid flags.

| Flag | Description |
| --- | --- |
| **STORAGE_PROTOCOL_COMMAND_FLAG_ADAPTER_REQUEST** | This flag indicates the request to target an adapter instead of device. |

### `Index`

Identifies the instance of temperature information. Starts from 0. Index 0 may indicate a composite value.

### `Threshold`

A signed value that indicates the temperature of the threshold, in degrees Celsius.

### `OverThreshold`

Indicates if the *Threshold* specifies the over or under temperature threshold. If **true**, set the **OverThreshold** temperature value of the device; otherwise, set the **UnderThreshold** temperature value.

### `Reserved`

Reserved for future use.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_set_temperature_threshold)

[STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_property_id)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query)

[STORAGE_TEMPERATURE_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_temperature_info)