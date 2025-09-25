## Description

The **PktMonClntNblDrop** function logs that a network packet was dropped. Additional information can be provided about why and where it got dropped.

## Parameters

### `CompContext`

Pointer to **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)** which holds the context for the component.

### `NetBufferList`

Pointer to the **[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)** structure.

### `PacketType`

The type of packet being logged. This must be one of the values defined in the **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)** enumeration.

### `PacketHeaderInformation`

Pointer to the **[PKTMON_PACKET_HEADER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_header_information)** structure containing the packet header information. Can be NULL.

### `UseOnlyFirstNbl`

When TRUE, indicates that only the first NBL in NetBufferList was dropped. Otherwise, all NBLs were dropped.

### `Direction`

Indicates the packet direction. Each component reports packets in two directions only, IN or OUT. Must be one of the values from the **[PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)** enumeration.

### `DropReason`

Integer that indicates the reason for the packet to be dropped.

| Value | Usage |
|--|--|
| 0 - 0x7FFFFFFF | Reserved for Microsoft. |
| 0x80000000 - 0xFFFFFFFF | Free to be used. |

### `LocationCode`

Integer that indicates the location where the packet got dropped.

| Value | Usage |
|--|--|
| 0 - 0x7FFFFFFF | Free to be used. |
| 0x80000000 - 0xFFFFFFFF | Reserved for Microsoft. |

## Remarks

## See also

- **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)**
- **[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)**
- **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)**
- **[PKTMON_PACKET_HEADER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_header_information)**
- **[PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)**