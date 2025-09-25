## Description

The **PktMonClntHeaderInfoLog** function logs that a network packet has flowed through, as opposed to being dropped.

## Parameters

### `EdgeContext`

Pointer to a **[PKTMON_EDGE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_edge_context)** structure which holds the edge context.

### `PacketHeaderInformation`

Pointer to a **[PKTMON_PACKET_HEADER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_header_information)** structure containing the packet header information.

### `Direction`

Indicates the packet direction. Each component reports packets in two directions only, IN or OUT. Must be one of the values from **[PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)** enumeration.

### `Context`

Pointer to a **[PKTMON_PACKET_CONTEXT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_context_in)** structure containing the packet context, which can represent a piece of data that is meaningful to the component, like a connection ID for example. Can be NULL.

## Remarks

Like **[PktMonClntNblLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbllog)**, **PktMonClntHeaderInfoLog** is also used for packet logging but does not require NBLs. **PktMonClntHeaderInfoLog** is useful when packet metadata needs to be logged.

## See also