# IFilter::GetChunk

## Description

Positions the filter at the beginning of the next chunk, or at the first chunk if this is the first call to the **GetChunk** method, and returns a description of the current chunk.

## Parameters

### `pStat` [out]

A pointer to a [STAT_CHUNK](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-stat_chunk) structure containing a description of the current chunk.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **FILTER_E_END_OF_CHUNKS** | The previous chunk is the last chunk. |
| **FILTER_E_EMBEDDING_UNAVAILABLE** | The next chunk is an embedding and no content filter is available. |
| **FILTER_E_LINK_UNAVAILABLE** | The next chunk is a link and no content filter is available. |
| **FILTER_E_PASSWORD** | Password or other security-related access failure. |
| **FILTER_E_ACCESS** | General access failure. |

## Remarks

If upon return *pStat* points to a [STAT_CHUNK](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-stat_chunk) structure with the **breakType** member equal to CHUNK_NO_BREAK, only the **idChunk** member will be updated with the new chunk identifier (ID) value. The other members of the **STAT_CHUNK** structure remain unchanged.

Internal value-type properties (chunks with a [CHUNKSTATE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunkstate) enumeration value of CHUNK_VALUE) cannot be concatenated using CHUNK_NO_BREAK. A single word cannot span more than two glued chunks.

Chunk ID zero is invalid.

Before the **GetChunk** method is called for the first time, there is no current chunk. After an error return code of anything other than FILTER_E_END_OF_CHUNKS the next call to the **GetChunk** method nevertheless retrieves the next chunk after the unavailable one.

### Notes to Callers

When the **GetChunk** method finishes, the chunk described in **pStat* is the current chunk. The chunk descriptor is owned by the routine calling the **GetChunk** method, but the property name pointer, which can be set in the property specification, is owned by the **GetChunk** method and should not be freed.

### Notes to Implementers

If a call to the **GetChunk** method of the content filter of a linked or embedded object returns FILTER_E_END_OF_CHUNKS, the implementation should return the next chunk of the linking or embedding object. For example, if a document has two embedded objects and the first has returned FILTER_E_END_OF_CHUNKS, then the outer content filter must call the **GetChunk** method of the content filter for the embedded object.

Before returning the results of a call to the **GetChunk** method on an embedded or linked object, check to make sure that the chunk ID is unique. If not, the implementer must renumber the chunk and keep a mapping of the new chunk ID.

## See also

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)

[STAT_CHUNK](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-stat_chunk)