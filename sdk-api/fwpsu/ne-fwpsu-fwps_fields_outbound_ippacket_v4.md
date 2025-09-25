## Description

Specifies the data field identifiers for the [FWPS_LAYER_OUTBOUND_IPPACKET_V4](https://learn.microsoft.com/windows/win32/api/fwpsu/ne-fwpsu-fwps_builtin_layers) and **FWPS_LAYER_OUTBOUND_IPPACKET_V4_DISCARD** run-time filtering layers.

## Constants

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_IP_LOCAL_ADDRESS_TYPE`

The local IP address type. The possible values are defined by the
NL_ADDRESS_TYPE enumeration

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_IP_LOCAL_INTERFACE`

The locally unique identifier (LUID) for the network interface associated with the
local IP address.

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_INTERFACE_INDEX`

The index of the network interface, as enumerated by the network stack.

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_SUB_INTERFACE_INDEX`

The index of the logical network interface, as enumerated by the network stack.

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see [Filtering condition flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

Supported in Windows Server 2008, Windows Vista SP1, and later versions of
Windows.

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_INTERFACE_TYPE`

The type of the arrival network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib).

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
*IfType* member of the **IP_ADAPTER_ADDRESSES** structure is **IF_TYPE_TUNNEL**. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://www.iana.org/assignments/ianaiftype-mib/ianaiftype-mib) and the
Windows SDK.

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_COMPARTMENT_ID`

The compartment that the network interface belongs to.

Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_OUTBOUND_IPPACKET_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

## See also