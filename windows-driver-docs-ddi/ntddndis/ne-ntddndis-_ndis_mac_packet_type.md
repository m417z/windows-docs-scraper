# _NDIS_MAC_PACKET_TYPE enumeration

## Description

The **NDIS_MAC_PACKET_TYPE** enumeration identifies the type of a destination address field in a media access control (MAC) header to be filtered.

## Constants

### `NdisMacPacketTypeUndefined`

An undefined MAC packet type.

### `NdisMacPacketTypeUnicast`

A unicast MAC packet type.

### `NdisMacPacketTypeMulticast`

A multicast MAC packet type.

### `NdisMacPacketTypeBroadcast`

A broadcast MAC packet type.

### `NdisMacPacketTypeMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The **NDIS_MAC_PACKET_TYPE** enumeration is used in the
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

## See also

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)