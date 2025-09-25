# FWPS_FIELDS_IPFORWARD_V6_ enumeration

## Description

The FWPS_FIELDS_IPFORWARD_V6 enumeration type specifies the data field identifiers for the
FWPS_LAYER_IPFORWARD_V6 and FWPS_LAYER_IPFORWARD_V6_DISCARD
[run-time filtering layers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_IPFORWARD_V6_IP_SOURCE_ADDRESS`

The source IP address.

### `FWPS_FIELD_IPFORWARD_V6_IP_DESTINATION_ADDRESS`

The destination IP address.

### `FWPS_FIELD_IPFORWARD_V6_IP_DESTINATION_ADDRESS_TYPE`

The destination IP address type. The possible values are defined by the
[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type) enumeration.

### `FWPS_FIELD_IPFORWARD_V6_IP_LOCAL_INTERFACE`

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) for the network interface associated with the
local IP address.

### `FWPS_FIELD_IPFORWARD_V6_IP_FORWARD_INTERFACE`

The LUID for the network interface on which the packet being forwarded is to be sent out.

### `FWPS_FIELD_IPFORWARD_V6_SOURCE_INTERFACE_INDEX`

The index of the source network interface, as enumerated by the network stack.

### `FWPS_FIELD_IPFORWARD_V6_SOURCE_SUB_INTERFACE_INDEX`

The index of the source logical network interface, as enumerated by the network stack.

### `FWPS_FIELD_IPFORWARD_V6_DESTINATION_INTERFACE_INDEX`

The index of the destination network interface, as enumerated by the network stack.

### `FWPS_FIELD_IPFORWARD_V6_DESTINATION_SUB_INTERFACE_INDEX`

The index of the destination logical network interface, as enumerated by the network stack.

### `FWPS_FIELD_IPFORWARD_V6_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_IPFORWARD_V6_IP_PHYSICAL_ARRIVAL_INTERFACE`

The
[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid) for the physical network interface that the
packet first arrived on.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_IPFORWARD_V6_ARRIVAL_INTERFACE_PROFILE_ID`

The profile identifier (network category) of the arrival interface. The possible network category
values are: public (1), private (2), or domain (3).

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_IPFORWARD_V6_IP_PHYSICAL_NEXTHOP_INTERFACE`

The
[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid) for the physical network interface that will be
used to continue forwarding of the outbound packet.

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_IPFORWARD_V6_NEXTHOP_INTERFACE_PROFILE_ID`

The profile identifier (network category) of the next-hop interface. The possible network category
values are: public (1), private (2), or domain (3).

**Note** Supported starting with Windows 7.

### `FWPS_FIELD_IPFORWARD_V6_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_IPFORWARD_V6_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[NL_ADDRESS_TYPE](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_address_type)