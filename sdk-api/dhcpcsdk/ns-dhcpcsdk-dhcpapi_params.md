# DHCPAPI_PARAMS structure

## Description

The **DHCPAPI_PARAMS** structure is used to request DHCP parameters.

## Members

### `Flags`

Reserved. Must be set to zero.

### `OptionId`

Identifier for the DHCP parameter being requested.

### `IsVendor`

Specifies whether the DHCP parameter is vendor-specific. Set to **TRUE** if the parameter is vendor-specific.

### `Data.size_is`

### `Data.size_is.nBytesData`

### `Data`

Pointer to the parameter data.

### `nBytesData`

Size of the data pointed to by **Data**, in bytes.

## See also

[DHCPAPI_PARAMS_ARRAY](https://learn.microsoft.com/windows/win32/api/dhcpcsdk/ns-dhcpcsdk-dhcpcapi_params_array)