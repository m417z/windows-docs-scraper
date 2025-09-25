# MIRACAST_CHUNK_DATA structure

## Description

Contains encode chunk data that is used when a user-mode driver calls the wireless display (Miracast) [GetNextChunkData](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_get_next_chunk_data) function.

## Members

### `ChunkInfo`

A [MIRACAST_CHUNK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_info) encode chunk information structure that the user-mode display driver wants to report.

### `PrivateDriverDataSize`

The size, in bytes, of the buffer that **pPrivateDriverData** points to.

### `PrivateDriverData`

Private data, of type **UCHAR**, that the user-mode display driver sends when it calls the [GetNextChunkData](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_get_next_chunk_data) function.

## See also

[GetNextChunkData](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_get_next_chunk_data)

[MIRACAST_CHUNK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_chunk_info)