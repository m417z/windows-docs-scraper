# FWPS_FIELDS_STREAM_V4_ enumeration

## Description

The FWPS_FIELDS_STREAM_V4 enumeration type specifies the data field identifiers for the
FWPS_LAYER_STREAM_V4 and FWPS_LAYER_STREAM_V4_DISCARD
[run-time filtering layers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_STREAM_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_STREAM_V4_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the
[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_STREAM_V4_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_STREAM_V4_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_STREAM_V4_IP_REMOTE_PORT`

The remote transport protocol port number.

### `FWPS_FIELD_STREAM_V4_DIRECTION`

The possible values are:

* FWP_DIRECTION_INBOUND
* FWP_DIRECTION_OUTBOUND

### `FWPS_FIELD_STREAM_V4_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_STREAM_V4_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_STREAM_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type)