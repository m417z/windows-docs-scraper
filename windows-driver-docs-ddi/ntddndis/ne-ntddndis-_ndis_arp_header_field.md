# _NDIS_ARP_HEADER_FIELD enumeration

## Description

The **NDIS_ARP_HEADER_FIELD** enumeration identifies the type of a field in an Address Resolution Protocol (ARP) header.

## Constants

### `NdisARPHeaderFieldUndefined`

An undefined ARP header field.

### `NdisARPHeaderFieldOperation`

The ARP operation field.

### `NdisARPHeaderFieldSPA`

The ARP source protocol address (SPA) field.

### `NdisARPHeaderFieldTPA`

The ARP target protocol address (TPA) field.

### `NdisARPHeaderFieldMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The **NDIS_ARP_HEADER_FIELD** enumeration is used in the
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

## See also

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)