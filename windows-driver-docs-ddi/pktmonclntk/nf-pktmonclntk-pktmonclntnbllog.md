## Description

The **PktMonClntNblLog** function logs that a network packet has flowed through an edge, as opposed to being dropped.

## Parameters

### `EdgeContext`

Pointer to the **[PKTMON_EDGE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_edge_context)** structure that holds the edge context. The *EdgeContext* parameter identifies the edge at which the action was taken.

### `NetBufferList`

Pointer to the **[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)** structure.

### `PacketType`

The type of packet being logged. This must be one of the values defined in the **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)** enumeration.

### `PacketHeaderInformation`

Pointer to the **[PKTMON_PACKET_HEADER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_header_information)** structure containing the packet header information. Can be NULL.

### `UseOnlyFirstNbl`

When TRUE, indicates that only the first NBL in NetBufferList should be used. Otherwise, all NBLs are used.

### `Direction`

Indicates the packet direction. Each component reports packets in two directions only, IN or OUT. Must be one of the values from the **[PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)** enumeration.

## Remarks

## See also

- **[PKTMON_EDGE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_edge_context)**
- **[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)**
- **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)**
- **[PKTMON_PACKET_HEADER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_header_information)**
- **[PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)**