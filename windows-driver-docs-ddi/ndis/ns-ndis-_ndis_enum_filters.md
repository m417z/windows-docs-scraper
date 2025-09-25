# _NDIS_ENUM_FILTERS structure

## Description

The NDIS_ENUM_FILTERS structure is returned from the call to the
[NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules) function to provide filter information for a filter stack.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
filter enumeration structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_ENUM_FILTERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_ENUM_FILTERS_REVISION_1.

### `Flags`

Reserved for future use.

### `NumberOfFilters`

The number of filter information structures that are included in the array in the
**Filter** member.

### `OffsetFirstFilter`

The offset, in bytes, to the first member of array at the
**Filter** member from the beginning of the NDIS_ENUM_FILTERS structure.

### `Filter`

An array that contains zero or more
[NDIS_FILTER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_interface) structures that
the call returns.

## Remarks

The
[NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules) function returns an NDIS_ENUM_FILTERS structure and the
**Filter** member of that structure contains an array of
[NDIS_FILTER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_interface) structures. The
array contains one NDIS_FILTER_INTERFACE structure for each NDIS 5.1 or earlier filter intermediate
driver or NDIS 6.0 or later NDIS filter module that is in the driver stack.

## See also

[NDIS_FILTER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_interface)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisEnumerateFilterModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisenumeratefiltermodules)