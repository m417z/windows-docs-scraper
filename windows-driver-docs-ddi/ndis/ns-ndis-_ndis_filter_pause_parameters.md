# _NDIS_FILTER_PAUSE_PARAMETERS structure

## Description

The NDIS_FILTER_PAUSE_PARAMETERS structure defines the pause parameters for the filter module.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_FILTER_PAUSE_PARAMETERS structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_FILTER_PAUSE_PARAMETERS, the
**Revision** member to NDIS_FILTER_PAUSE_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_FILTER_PAUSE_PARAMETERS_REVISION_1.

### `Flags`

Reserved.

### `PauseReason`

**Note** This member is deprecated for NDIS 6.40 and later drivers.

The value will always be NDIS_PAUSE_NDIS_INTERNAL.

## Remarks

To define filter module pause parameters, NDIS passes a pointer to an NDIS_FILTER_PAUSE_PARAMETERS
structure to the
[FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause) function.

## See also

[FilterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_pause)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)