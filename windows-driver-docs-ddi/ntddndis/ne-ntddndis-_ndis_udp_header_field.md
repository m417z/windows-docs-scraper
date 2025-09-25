# _NDIS_UDP_HEADER_FIELD enumeration

## Description

The **NDIS_UDP_HEADER_FIELD** enumeration identifies the type of a field in a User Datagram Protocol
(UDP) header to be filtered.

## Constants

### `NdisUdpHeaderFieldUndefined`

An undefined UDP header field.

### `NdisUdpHeaderFieldDestinationPort`

The UDP destination port field.

### `NdisUdpHeaderFieldMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The **NDIS_UDP_HEADER_FIELD** enumeration is used in the
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

## See also

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)