# _NDIS_IPV4_HEADER_FIELD enumeration

## Description

The **NDIS_IPV4_HEADER_FIELD** enumeration identifies the type of a field in an IP version 4 (IPv4) header to be filtered.

## Constants

### `NdisIPv4HeaderFieldUndefined`

An undefined IPV4 header field.

### `NdisIPv4HeaderFieldProtocol`

The IPv4 protocol field.

### `NdisIPv4HeaderFieldMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The **NDIS_IPV4_HEADER_FIELD** enumeration is used in the
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

## See also

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)