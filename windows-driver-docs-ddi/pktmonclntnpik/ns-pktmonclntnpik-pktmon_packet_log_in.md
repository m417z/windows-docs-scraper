## Description

The **PKTMON_PACKET_LOG_IN** structure contains information about a packet being logged for monitoring purposes. This structure is passed to both packet log and packet drop callbacks to provide packet metadata.

## Members

### `Header`

A [PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header) structure used for versioning and size validation.

### `Buffer`

A pointer to the packet buffer. The interpretation of this pointer depends on the `BufferType` field.

### `BufferType`

A **[PKTMON_BUFFER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ne-pktmonclntnpik-pktmon_buffer_type)** enumeration value that specifies the format of the packet buffer (e.g., NBL chain, single NBL, WSK buffer, or none).

### `PacketType`

A **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)** enumeration value that indicates the type of packet being logged (e.g., Ethernet, IP, etc.).

### `Direction`

A **[PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)** enumeration value that specifies whether the packet is inbound or outbound relative to the monitoring edge.

### `Flags`

Flags providing additional information about the packet logging operation. The specific flags are defined by the implementation.

### `PacketHeaderInfo`

An optional pointer to a **[PKTMON_PACKET_HEADER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_header_info)** structure containing parsed packet header information. Can be NULL if header information is not available.

## Remarks

This structure is used by both **[PKTMON_PROVIDER_PACKET_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_log)** and **[PKTMON_PROVIDER_PACKET_DROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_drop)** callbacks.

## See also

- [PKTMON_PROVIDER_PACKET_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_log)
- [PKTMON_PROVIDER_PACKET_DROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_drop)
- [PKTMON_BUFFER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ne-pktmonclntnpik-pktmon_buffer_type)