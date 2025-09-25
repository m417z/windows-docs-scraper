## Description

Specifies the data field identifiers for the [FWPS_LAYER_ALE_BIND_REDIRECT_V4](https://learn.microsoft.com/windows/win32/api/fwpsu/ne-fwpsu-fwps_builtin_layers) run-time filtering layer.

## Constants

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_ALE_APP_ID`

The full path of the application.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_ALE_USER_ID`

The identifier of the local user.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the [NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_IP_PROTOCOL`

The IP protocol number, as specified in RFC 1700.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see [Filtering condition flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_ALE_PACKAGE_ID`

The package identifier is a security identifier (SID) that identifies the associated AppContainer process. For more information about the SID structure, see the description for the SID structure in the Microsoft Windows SDK documentation.

Supported starting with Windows 8.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_ALE_SECURITY_ATTRIBUTE_FQBN_VALUE`

The fully qualified binary name (FQBN) value of the application.

Supported starting with Windows 10.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_COMPARTMENT_ID`

The compartment that the network interface belongs to.

Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_PACKAGE_FAMILY_NAME`

Indicates that the resource is a Package Family Name string.

Supported starting with Windows Server 2022 23H2.

### `FWPS_FIELD_ALE_BIND_REDIRECT_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

## See also