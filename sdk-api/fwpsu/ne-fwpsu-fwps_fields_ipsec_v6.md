## Description

Specifies the data field identifiers for the [FWPS_LAYER_IPSEC_V6](https://learn.microsoft.com/windows/win32/api/fwpsu/ne-fwpsu-fwps_builtin_layers) run-time filtering layer.

## Constants

### `FWPS_FIELD_IPSEC_V6_IP_PROTOCOL`

The IP protocol number, as specified in RFC 1700.

### `FWPS_FIELD_IPSEC_V6_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_IPSEC_V6_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_IPSEC_V6_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_IPSEC_V6_IP_REMOTE_PORT`

The remote transport protocol port number.

### `FWPS_FIELD_IPSEC_V6_IP_LOCAL_INTERFACE`

The locally unique identifier (LUID) for the network interface associated with the
local IP address.

### `FWPS_FIELD_IPSEC_V6_PROFILE_ID`

The profile identifier (network category) of the network interface. The possible network category
values are: public (1), private (2), or domain (3).

Supported starting with Windows 7.

### `FWPS_FIELD_IPSEC_V6_IPSEC_SECURITY_REALM_ID`

The IPsec security realm identifier.

Supported starting with Windows 10.

### `FWPS_FIELD_IPSEC_V6_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

## See also