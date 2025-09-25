# _NDIS_MINIPORT_RESTART_PARAMETERS structure

## Description

The NDIS_MINIPORT_RESTART_PARAMETERS structure defines the restart parameters for a miniport
adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_RESTART_PARAMETERS structure. NDIS sets the
**Type** member of the structure that
**Header** specified to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_MINIPORT_RESTART_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MINIPORT_RESTART_PARAMETERS_REVISION_1.

### `RestartAttributes`

A pointer to an
[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure.

### `Flags`

Reserved.

## Remarks

To define miniport adapter restart parameters, NDIS passes a pointer to an
NDIS_MINIPORT_RESTART_PARAMETERS structure to the
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function.

## See also

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes)