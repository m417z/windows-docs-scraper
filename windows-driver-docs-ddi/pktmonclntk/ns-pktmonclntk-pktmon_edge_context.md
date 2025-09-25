## Description

The **PKTMON_EDGE_CONTEXT** structure holds the context for an edge.

## Members

### `ListLink`

A **[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry)** structure that is used to link the edge context to the list of edge contexts that belong to a component.

### `EdgeHandle`

A handle to the edge.

### `CompContext`

A pointer to the **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)** structure that holds the context for the component.

### `PacketType`

The **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)**.

## Remarks

## See also

- **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)**
- **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)**