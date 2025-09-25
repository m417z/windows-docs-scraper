# MIRACAST_CHUNK_INFO structure

## Description

Contains info about a specified wireless display (Miracast) encode chunk.

## Members

### `ChunkType`

The type of chunk that is to be processed, specified as a [MIRACAST_CHUNK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ne-netdispumdddi-miracast_chunk_type) enumeration value.

### `ChunkId`

The identifier for this chunk, of type [MIRACAST_CHUNK_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_id).

### `ProcessingTime`

The time, in microseconds, that it took to process this chunk.

### `EncodeRate`

The encode bit rate, in kilobits per second, that the user-mode driver reported for this chunk.

## See also

[MIRACAST_CHUNK_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_id)

[MIRACAST_CHUNK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ne-netdispumdddi-miracast_chunk_type)