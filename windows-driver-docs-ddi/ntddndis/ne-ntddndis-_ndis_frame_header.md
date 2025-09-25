# _NDIS_FRAME_HEADER enumeration

## Description

The **NDIS_FRAME_HEADER** enumeration identifies the type of header in a network data frame.

## Constants

### `NdisFrameHeaderUndefined`

An undefined frame header type.

### `NdisFrameHeaderMac`

A media access control (MAC) header.

### `NdisFrameHeaderArp`

An Address Resolution Protocol (ARP) header.

### `NdisFrameHeaderIPv4`

An IP version 4 (IPv4) header.

### `NdisFrameHeaderIPv6`

An IP version 6 (IPv6) header.

### `NdisFrameHeaderUdp`

A User Datagram Protocol
(UDP) header.

### `NdisFrameHeaderMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The NDIS_FRAME_HEADER enumeration is used in the
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

## See also

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)