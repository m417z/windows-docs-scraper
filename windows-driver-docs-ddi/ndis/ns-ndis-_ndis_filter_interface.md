# _NDIS_FILTER_INTERFACE structure

## Description

The NDIS_FILTER_INTERFACE structure defines the attributes for an NDIS filter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
filter interface structure.

NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT.

If the handle passed to [NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules) belongs to an NDIS 6.30 or later object, then NDIS sets **Revision** to NDIS_FILTER_INTERFACE_REVISION_2 and **Size** to NDIS_SIZEOF_FILTER_INTERFACE_REVISION_2.

If the handle passed to [NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules) belongs to an NDIS 6.20 or earlier object, then NDIS sets **Revision** to NDIS_FILTER_INTERFACE_REVISION_1 and **Size** to NDIS_SIZEOF_FILTER_INTERFACE_REVISION_1.

### `Flags`

A bit field that defines the type of NDIS driver that implements the filter. This member must be
set to one of the following driver types:

#### NDIS_FILTER_INTERFACE_IM_FILTER

The filter is implemented in an NDIS 5.1 or earlier filter intermediate driver.

#### NDIS_FILTER_INTERFACE_LW_FILTER

The filter is implemented in an NDIS 6.0 or later filter driver.

#### NDIS_FILTER_INTERFACE_SEND_BYPASS

The filter is currently not attached to the send path. This flag is only set if **Header.Revision** is greater than or equal to NDIS_FILTER_INTERFACE_REVISION_2.

#### NDIS_FILTER_INTERFACE_RECEIVE_BYPASS

The filter is currently not attached to the receive path. This flag is only set if **Header.Revision** is greater than or equal to NDIS_FILTER_INTERFACE_REVISION_2.

### `FilterType`

The behavior type for the filter. This type must be one of the following values:

#### NdisFilterTypeMonitoring = 1

A monitoring filter.

#### NdisFilterTypeModifying = 2

A modifying filter.

### `FilterRunType`

The runtime attachment priority type for the filter. This type must be one of the following
values:

#### NdisFilterRunTypeMandatory = 1

A mandatory filter. If the filter does not attach to the driver stack, NDIS will tear down the
rest of the stack.

#### NdisFilterRunTypeOptional = 2

An optional filter. If the filter does not attach to the driver stack, NDIS will not tear down the
rest of the stack.

### `IfIndex`

The NDIS interface index of the filter module.

### `NetLuid`

The
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value that is assigned to the filter
module. The NET_LUID is equivalent to the interface name (ifName in
RFC 2863).

### `FilterClass`

A UNICODE string that specifies the filter class. This string is the same as the
**FilterClass** INF file entry.

### `FilterInstanceName`

The filter instance name.

## Remarks

The
[NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules) function returns one NDIS_FILTER_INTERFACE structure for each filter in
the driver stack. The
**Flags** member identifies the filter as an NDIS 5.1 or earlier filter intermediate driver or an NDIS
6.0 or later NDIS filter module.

A light-weight filter may dynamically insert or remove itself from the send or receive path by calling [NdisFRestartFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartfilter) and providing a [NDIS_FILTER_PARTIAL_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_partial_characteristics) structure to [NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules)