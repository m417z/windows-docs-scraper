## Description

Specifies the data field identifiers for the [FWPS_LAYER_ALE_RESOURCE_ASSIGNMENT_V4](https://learn.microsoft.com/windows/win32/api/fwpsu/ne-fwpsu-fwps_builtin_layers) and **FWPS_LAYER_ALE_RESOURCE_ASSIGNMENT_V4_DISCARD** run-time filtering layers.

## Constants

### `FWPS_FIELD_DATAGRAM_DATA_V4_IP_PROTOCOL`

The IP protocol number, as specified in RFC 1700.

### `FWPS_FIELD_DATAGRAM_DATA_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_DATAGRAM_DATA_V4_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_DATAGRAM_DATA_V4_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the [NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_DATAGRAM_DATA_V4_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_DATAGRAM_DATA_V4_IP_REMOTE_PORT`

The remote transport protocol port number.

### `FWPS_FIELD_DATAGRAM_DATA_V4_IP_LOCAL_INTERFACE`

The locally unique identifier (LUID) for the network interface associated with the local IP address.

### `FWPS_FIELD_DATAGRAM_DATA_V4_NEXTHOP_INTERFACE_INDEX`

The index of the network interface that will be used to continue forwarding of the outbound
packet, as enumerated by the network stack.

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_DATAGRAM_DATA_V4_SUB_INTERFACE_INDEX`

The index of the network subinterface, as enumerated by the network stack.

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_DATAGRAM_DATA_V4_DIRECTION`

The possible values are **FWP_DIRECTION_INBOUND** and **FWP_DIRECTION_OUTBOUND**.

### `FWPS_FIELD_DATAGRAM_DATA_V4_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see [Filtering condition flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_DATAGRAM_DATA_V4_INTERFACE_TYPE`

The type of the local network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib).

### `FWPS_FIELD_DATAGRAM_DATA_V4_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
*IfType* member of the **IP_ADAPTER_ADDRESSES** structure is **IF_TYPE_TUNNEL**. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib) and the
Windows SDK.

### `FWPS_FIELD_DATAGRAM_DATA_V4_COMPARTMENT_ID`

The compartment that the network interface belongs to.

Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_DATAGRAM_DATA_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the Network Driver Interface Specification (NDIS) header files and binaries.

## Remarks

The following macros in `fwpsu.h` are defined with **FWPS_FIELDS_DATAGRAM_DATA_V4** enumeration values:

```cpp
#define FWPS_FIELD_DATAGRAM_DATA_V4_ICMP_TYPE \
        FWPS_FIELD_DATAGRAM_DATA_V4_IP_LOCAL_PORT

#define FWPS_FIELD_DATAGRAM_DATA_V4_ICMP_CODE \
        FWPS_FIELD_DATAGRAM_DATA_V4_IP_REMOTE_PORT
```

Those macros are used to access the following IPV4 data fields:

FWPS_FIELD_DATAGRAM_DATA_V4_ICMP_TYPE

The ICMP type field, as specified in RFC 792.

FWPS_FIELD_DATAGRAM_DATA_V4_ICMP_CODE

The ICMP code field, as specified in RFC 792.

## See also