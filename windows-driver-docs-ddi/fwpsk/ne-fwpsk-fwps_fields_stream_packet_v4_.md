# FWPS_FIELDS_STREAM_PACKET_V4_ enumeration

## Description

The FWPS_FIELDS_STREAM_PACKET_V4 enumeration type specifies the data field identifiers for the
FWPS_LAYER_STREAM_PACKET_V4
[run-time filtering layer](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## Constants

### `FWPS_FIELD_STREAM_PACKET_V4_IP_LOCAL_ADDRESS`

The local IP address.

### `FWPS_FIELD_STREAM_PACKET_V4_IP_REMOTE_ADDRESS`

The remote IP address.

### `FWPS_FIELD_STREAM_PACKET_V4_IP_LOCAL_PORT`

The local transport protocol port number.

### `FWPS_FIELD_STREAM_PACKET_V4_IP_REMOTE_PORT`

The remote transport protocol port number.

### `FWPS_FIELD_STREAM_PACKET_V4_IP_LOCAL_INTERFACE`

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) for the network interface associated with the
local IP address.

### `FWPS_FIELD_STREAM_PACKET_V4_INTERFACE_INDEX`

The index of the network interface, as enumerated by the network stack.

### `FWPS_FIELD_STREAM_PACKET_V4_SUB_INTERFACE_INDEX`

The index of the logical network interface, as enumerated by the network stack.

### `FWPS_FIELD_STREAM_PACKET_V4_DIRECTION`

The possible values are:

* FWP_DIRECTION_INBOUND
* FWP_DIRECTION_OUTBOUND

### `FWPS_FIELD_STREAM_PACKET_V4_FLAGS`

A bitwise OR of a combination of filtering condition flags. For information about the possible
flags, see
[Filtering Condition Flags](https://learn.microsoft.com/windows-hardware/drivers/network/filtering-condition-flags).

### `FWPS_FIELD_STREAM_PACKET_V4_INTERFACE_TYPE`

The type of the local network interface, as defined by the Internet Assigned Numbers Authority
(IANA). For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066).

### `FWPS_FIELD_STREAM_PACKET_V4_TUNNEL_TYPE`

The encapsulation method used by a tunnel if the
**IfType** member of the IP_ADAPTER_ADDRESSES structure is IF_TYPE_TUNNEL. The tunnel type is defined
by IANA. For more information, see
[IANAifType-MIB Definitions](https://go.microsoft.com/fwlink/p/?linkid=60066) and the
Windows SDK.

### `FWPS_FIELD_STREAM_PACKET_V4_COMPARTMENT_ID`

The compartment that the network interface belongs to.

**Note** Supported starting with Windows 10, version 1703.

### `FWPS_FIELD_STREAM_PACKET_V4_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)