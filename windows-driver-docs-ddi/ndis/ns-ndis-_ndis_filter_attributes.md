# _NDIS_FILTER_ATTRIBUTES structure

## Description

The NDIS_FILTER_ATTRIBUTES structure defines the attributes of a filter module.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
filter attributes structure (NDIS_FILTER_ATTRIBUTES). Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_FILTER_ATTRIBUTES, the
**Revision** member to NDIS_FILTER_ATTRIBUTES_REVISION_1, and the
**Size** member to NDIS_SIZEOF_FILTER_ATTRIBUTES_REVISION_1.

### `Flags`

Reserved. Set this member to zero.

## Remarks

A filter drivers passes an NDIS_FILTER_ATTRIBUTES structure to the
[NdisFSetAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsetattributes) function.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisFSetAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsetattributes)