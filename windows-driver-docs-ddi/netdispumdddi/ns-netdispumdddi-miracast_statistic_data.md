# MIRACAST_STATISTIC_DATA structure

## Description

Contains Miracast statistics data that the user-mode display driver reports to the operating system.

## Members

### `StatisticType`

The type of statistics data from the [MIRACAST_STATISTIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ne-netdispumdddi-miracast_statistic_type) enumeration.

### `EncodeComplete`

### `EncodeComplete.ChunkInfo`

A [MIRACAST_CHUNK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_info) structure that provides info about an encode chunk that is identified by the **ChunkId** member.

### `ChunkSent`

### `ChunkSent.ChunkId`

The identifier for this chunk, of type [MIRACAST_CHUNK_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_id).

### `ProtocolEvent`

### `ProtocolEvent.Event`

The type of protocol event, given as a value of the [MIRACAST_PROTOCOL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ne-netdispumdddi-miracast_protocol_event) enumeration.

## See also

[MIRACAST_CHUNK_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_id)

[MIRACAST_CHUNK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_info)

[MIRACAST_PROTOCOL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ne-netdispumdddi-miracast_protocol_event)

[MIRACAST_STATISTIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ne-netdispumdddi-miracast_statistic_type)