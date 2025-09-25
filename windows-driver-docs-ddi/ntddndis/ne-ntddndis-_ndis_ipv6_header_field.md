# _NDIS_IPV6_HEADER_FIELD enumeration

## Description

The **NDIS_IPV6_HEADER_FIELD** enumeration identifies the type of a field in an IP version 6 (IPv6) header to be filtered.

## Constants

### `NdisIPv6HeaderFieldUndefined`

An undefined IPv6 header field.

### `NdisIPv6HeaderFieldProtocol`

The IPv6 protocol field.

### `NdisIPv6HeaderFieldMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The **NDIS_IPV6_HEADER_FIELD** enumeration is used in the
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

## See also

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)