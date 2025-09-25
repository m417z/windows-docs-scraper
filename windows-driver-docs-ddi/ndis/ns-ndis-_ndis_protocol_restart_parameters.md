# _NDIS_PROTOCOL_RESTART_PARAMETERS structure

## Description

The NDIS_PROTOCOL_RESTART_PARAMETERS structure defines restart parameters for a protocol driver when
NDIS calls the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function to
indicate a
**NetEventRestart** event.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_PROTOCOL_RESTART_PARAMETERS structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_PROTOCOL_RESTART_PARAMETERS, the
**Revision** member to NDIS_PROTOCOL_RESTART_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_PROTOCOL_RESTART_PARAMETERS_REVISION_1.

### `FilterModuleNameBuffer`

A list of the names of the underlying filter modules. For each name, the buffer contains a USHORT
value followed by a wide character string. Use the first USHORT value in the buffer to determine the
length of the first string. Use the length of the first string to determine the start of the next
string. Continue in this manner until the number of bytes that are retrieved from the buffer equals the
number of bytes that are specified in the
**FilterModuleNameBufferLength** member.

### `FilterModuleNameBufferLength`

The length, in bytes, of the buffer in the
**FilterModuleNameBuffer** member.

### `RestartAttributes`

A pointer to the first entry in a list of
[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structures.
Use the
**Next** member of the NDIS_RESTART_ATTRIBUTES structure to get the next structure in the list.

### `BoundIfIndex`

The NDIS network interface index of the highest-level interface that is stacked on the miniport
adapter. That is, if there are virtual miniports or filter modules that are installed over the miniport
adapter, this member is the
*IfIndex* of the highest-level virtual miniport or filter module.

### `BoundIfNetluid`

The NDIS
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value (that is also the network interface
name (*ifName* in
RFC 2863)) of the highest-level interface that is stacked on the miniport
adapter. That is, if there are virtual miniports or filter modules that are installed over the miniport
adapter, this member is the NET_LUID value of the highest-level virtual miniport or filter
module.

### `Flags`

Reserved for future use.

## Remarks

NDIS passes an NDIS_PROTOCOL_RESTART_PARAMETERS structure to a protocol driver when it calls the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function to
indicate a
**NetEventRestart** event.

Each name that is specified in the buffer in the
**FilterModuleNameBuffer** member is not guaranteed to be NULL-terminated. The USHORT value at the
start of each string contains the length, in bytes, of the string. Protocol drivers should check the
value of the
**FilterModuleNameBufferLength** member before they access the buffer.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)