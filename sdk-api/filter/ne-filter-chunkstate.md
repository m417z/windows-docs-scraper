# CHUNKSTATE enumeration

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Specifies whether the current chunk is a text-type property or a value-type property.

## Constants

### `CHUNK_TEXT:0x1`

The current chunk is a text-type property.

### `CHUNK_VALUE:0x2`

The current chunk is a value-type property.

### `CHUNK_FILTER_OWNED_VALUE:0x4`

Reserved.

### `CHUNK_IMAGE:0x8`

The current chunk is an image.

## See also

[IFilter::GetChunk](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-getchunk)

[IFilter::GetText](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-gettext)

[STAT_CHUNK](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-stat_chunk)