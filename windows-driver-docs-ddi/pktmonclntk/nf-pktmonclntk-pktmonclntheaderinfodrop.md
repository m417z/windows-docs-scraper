## Description

The **PktMonClntHeaderInfoDrop** function logs that a network packet was dropped.

## Parameters

### `CompContext`

Pointer to the **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)** structure that holds the context for the component.

### `PacketType`

The type of packet being logged. This must be one of the values defined in the **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)** enumeration.

### `PacketHeaderInformation`

Pointer to a **[PKTMON_PACKET_HEADER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_header_information)** structure containing the packet header information.

### `Direction`

Indicates the packet direction. Each component reports packets in two directions only, IN or OUT. Must be one of the values from **[PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)** enumeration.

### `DropReason`

Integer that indicates the reason for the packet to be dropped.

| Value | Usage |
|--|--|
| 0 - 0x7FFFFFFF | Reserved for Microsoft. |
| 0x80000000 - 0xFFFFFFFF | Free to be used. |

### `LocationCode`

Integer that indicates the location where the packet was dropped.

| Value | Usage |
|--|--|
| 0 - 0x7FFFFFFF | Free to be used. |
| 0x80000000 - 0xFFFFFFFF | Reserved for Microsoft. |

### `Context`

Pointer to a **[PKTMON_PACKET_CONTEXT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_context_in)** structure containing the packet context. Can be NULL.

## Remarks

## See also

- **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)**
- **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)**
- **[PKTMON_PACKET_HEADER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_header_information)**
- **[PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)**
- **[PKTMON_PACKET_CONTEXT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_packet_context_in)**