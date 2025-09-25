# _NDIS_PROTOCOL_PAUSE_PARAMETERS structure

## Description

NDIS passes an NDIS_PROTOCOL_PAUSE_PARAMETERS structure to a protocol driver when it calls the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function to
indicate a
**NetEventPause** event.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_PROTOCOL_PAUSE_PARAMETERS structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_PROTOCOL_PAUSE_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_PROTOCOL_PAUSE_PARAMETERS_REVISION_1.

### `Flags`

Reserved.

### `PauseReason`

**Note** This member is deprecated for NDIS 6.40 and later drivers.

The value will always be NDIS_PAUSE_NDIS_INTERNAL.

## Remarks

To specify the pause parameters for a binding, NDIS passes a pointer to an
NDIS_PROTOCOL_PAUSE_PARAMETERS structure to the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function when
NDIS indicates a
**NetEventPause** event.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)