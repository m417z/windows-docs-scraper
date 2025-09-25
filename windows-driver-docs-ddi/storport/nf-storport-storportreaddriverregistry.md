## Description

The **StorPortReadDriverRegistry** function is used by the miniport to read the registry data for a given driver object.

## Parameters

### `DriverObject`

The driver object for which registry data is to be read.

### `ValueName`

The name of the registry data to be returned.

### `ValueDataLength`

The size, in bytes, of the buffer provided for the returned data in the *ValueData* parameter.

### `ValueData`

The buffer for the retrieved data.

## Return value

Returns TRUE if the registry data was read and copied into buffer successfully, otherwise returns FALSE.

## Remarks

The values are located under the driver's service key, for example, HKLM\System\CurrentControlSet\Services\\<*DriverName*>\\<*ValueName*>. The value can be any REG_XXXX type.

## See also