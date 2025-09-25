# FWPS_FIELDS_OUTBOUND_ICMP_ERROR_V4_ enumeration

## Description

The FWPS_FIELDS_OUTBOUND_ICMP_ERROR_V4 enumeration type specifies the data field identifiers for the
FWPS_LAYER_OUTBOUND_ICMP_ERROR_V4 and FWPS_LAYER_OUTBOUND_ICMP_ERROR_V4_DISCARD
[run-time filtering layers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the
[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_IP_LOCAL_INTERFACE`

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) for the network interface associated with the
local IP address.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_ICMP_TYPE`

The ICMP type field, as specified in RFC 792.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_ICMP_CODE`

The ICMP code field, as specified in RFC 792.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_INTERFACE_INDEX`

The index of the network interface, as enumerated by the network stack.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_SUB_INTERFACE_INDEX`

The index of the logical network interface, as enumerated by the network stack.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_INTERFACE_TYPE`

The type of the arrival network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066) and the
Windows SDK.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

**Note** Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_NEXTHOP_INTERFACE_PROFILE_ID`

The profile identifier (network category) of the next-hop interface. The possible network category
values are: public (1), private (2), or domain (3).

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_INTERFACE_QUARANTINE_EPOCH`

The time that has passed since the last media state change occurred for the network interface.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type)