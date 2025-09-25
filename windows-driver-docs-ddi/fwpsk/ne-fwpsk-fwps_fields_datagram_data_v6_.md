# FWPS_FIELDS_DATAGRAM_DATA_V6_ enumeration

## Description

The FWPS_FIELDS_DATAGRAM_DATA_V6 enumeration type specifies the data field identifiers for the
FWPS_LAYER_DATAGRAM_DATA_V6 and FWPS_LAYER_DATAGRAM_DATA_V6_DISCARD
[run-time filtering layers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_DATAGRAM_DATA_V6_IP_PROTOCOL`

The IP protocol number, as specified in RFC 1700.

### `FWPS_FIELD_DATAGRAM_DATA_V6_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_DATAGRAM_DATA_V6_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_DATAGRAM_DATA_V6_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the
[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_DATAGRAM_DATA_V6_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_DATAGRAM_DATA_V6_IP_REMOTE_PORT`

The remote transport protocol port number.

### `FWPS_FIELD_DATAGRAM_DATA_V6_IP_LOCAL_INTERFACE`

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) for the network interface associated with the
local IP address.

### `FWPS_FIELD_DATAGRAM_DATA_V6_INTERFACE_INDEX`

The index of the network interface, as enumerated by the network stack.

### `FWPS_FIELD_DATAGRAM_DATA_V6_SUB_INTERFACE_INDEX`

The index of the logical network interface, as enumerated by the network stack.

### `FWPS_FIELD_DATAGRAM_DATA_V6_DIRECTION`

The possible values are:

* FWP_DIRECTION_INBOUND
* FWP_DIRECTION_OUTBOUND

### `FWPS_FIELD_DATAGRAM_DATA_V6_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_DATAGRAM_DATA_V6_INTERFACE_TYPE`

The type of the network interface, as defined by the Internet Assigned Numbers Authority (IANA).
For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

### `FWPS_FIELD_DATAGRAM_DATA_V6_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066) and the
Windows SDK.

### `FWPS_FIELD_DATAGRAM_DATA_V6_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_DATAGRAM_DATA_V6_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The following macros in
*Fwpsk.h* are defined with FWPS_FIELDS_DATAGRAM_DATA_V6 enumeration values:

```

#define FWPS_FIELD_DATAGRAM_DATA_V6_ICMP_TYPE \
        FWPS_FIELD_DATAGRAM_DATA_V6_IP_LOCAL_PORT

#define FWPS_FIELD_DATAGRAM_DATA_V6_ICMP_CODE \
        FWPS_FIELD_DATAGRAM_DATA_V6_IP_REMOTE_PORT

```

These macros are used to access the following IPV6 data fields:

FWPS_FIELD_DATAGRAM_DATA_V6_ICMP_TYPE
The ICMP type field, as specified in RFC 792.

FWPS_FIELD_DATAGRAM_DATA_V6_ICMP_CODE
The ICMP code field, as specified in RFC 792.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type)