# _NDIS_RESTART_ATTRIBUTES structure

## Description

The NDIS_RESTART_ATTRIBUTES structure identifies an attributes entry in a linked list of restart
attributes.

## Members

### `Next`

A pointer to an NDIS_RESTART_ATTRIBUTES structure that you can use to access the next set of
restart attributes in the linked list of attributes. If there are no additional attributes, this member
is **NULL**.

### `Oid`

The NDIS object identifier for the information that is in the
**Data** member. For example, if
**Oid** is
[OID_GEN_MINIPORT_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-miniport-restart-attributes), the
**Data** member contains an
[NDIS_RESTART_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_general_attributes) structure.

### `DataLength`

The length, in bytes, of the information that is stored in the
**Data** member.

### `Data`

A buffer that contains the information that is associated with the OID that is specified in the
**Oid** member.

## Remarks

When NDIS restarts a driver stack, NDIS passes a pointer to a linked list of restart attributes to
miniport, filter, and protocol drivers.

When it calls a miniport driver's
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function, NDIS passes a
pointer to an NDIS_RESTART_ATTRIBUTES structure to the miniport driver in the
**RestartAttributes** member of the
[NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters) structure.

When it calls a filter driver's
[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart) function, NDIS passes a
pointer to an NDIS_RESTART_ATTRIBUTES structure to the filter driver in the
**RestartAttributes** member of the
[NDIS_FILTER_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_restart_parameters) structure.

When it restarts a protocol binding, NDIS provides a pointer to an NDIS_RESTART_ATTRIBUTES structure
in the
**RestartAttributes** member of the
[NDIS_PROTOCOL_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_restart_parameters) structure. To restart a protocol binding, NDIS calls a protocol
driver's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function. The
**NetPnPEvent** member of the
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure, that NDIS passes to
*ProtocolNetPnPEvent*, contains a
[NET_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpnp/ns-netpnp-_net_pnp_event) structure. The NET_PNP_EVENT
structure specifies
**NetEventRestart** in the
**NetEvent** member and a pointer to the NDIS_PROTOCOL_RESTART_PARAMETERS structure in the
**Buffer** member.

If the restart attributes pointer that NDIS passes to NDIS drivers is **NULL**, the drivers should not
propagate their attributes changes up the driver stack. In this situation, drivers should not modify, or
report any attributes changes.

If the restart attributes pointer is not **NULL**, the linked list of NDIS_RESTART_ATTRIBUTES structures
has at least one entry that contains an
[NDIS_RESTART_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_general_attributes) structure. The rest of the entries, if any, contain media-specific
attributes.

## See also

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)

[NDIS_FILTER_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_restart_parameters)

[NDIS_MINIPORT_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_restart_parameters)

[NDIS_PROTOCOL_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_restart_parameters)

[NDIS_RESTART_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_general_attributes)

[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification)

[OID_GEN_MINIPORT_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-miniport-restart-attributes)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)