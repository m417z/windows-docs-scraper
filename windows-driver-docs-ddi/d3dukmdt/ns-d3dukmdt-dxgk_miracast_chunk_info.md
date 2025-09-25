## Description

Contains info about a specified wireless display (Miracast) encode chunk.

## Members

### `ChunkType`

The type of chunk that is to be processed, specified as a [DXGK_MIRACAST_CHUNK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_dxgk_miracast_chunk_type) enumeration value.

### `ChunkId`

The identifier for this chunk, of type [**DXGK_MIRACAST_CHUNK_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_miracast_chunk_id).

### `ProcessingTime`

The time, in microseconds, that it took to process this chunk.

### `EncodeRate`

The encode bit rate, in kilobits per second, that the display miniport driver reported for this chunk.

## See also

[**DXGK_MIRACAST_CHUNK_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_miracast_chunk_id)

[DXGK_MIRACAST_CHUNK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_dxgk_miracast_chunk_type)