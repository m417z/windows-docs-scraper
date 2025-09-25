# _NDIS_MAC_HEADER_FIELD enumeration

## Description

The **NDIS_MAC_HEADER_FIELD** enumeration identifies the type of a field in a media access control (MAC) header to be filtered.

## Constants

### `NdisMacHeaderFieldUndefined`

An undefined MAC header field.

### `NdisMacHeaderFieldDestinationAddress`

A destination address field.

### `NdisMacHeaderFieldSourceAddress`

A source address field.

### `NdisMacHeaderFieldProtocol`

A protocol field in the DEC/Intel/Xerox (DIX) Ethernet

MAC header.

### `NdisMacHeaderFieldVlanId`

A virtual local area network (VLAN) identifier field.

### `NdisMacHeaderFieldPriority`

A VLAN priority field.

### `NdisMacHeaderFieldPacketType`

A packet type field in the IEEE 802.2 subnetwork access protocol (SNAP) header of an 802.3

MAC header.

### `NdisMacHeaderFieldMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The NDIS_MAC_HEADER_FIELD enumeration is used in the
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

## See also

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)