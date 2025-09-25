# HTTP_BYTE_RANGE structure

## Description

The
**HTTP_BYTE_RANGE** structure is used to specify a byte range within a cached response fragment, file, or other data block.

## Members

### `StartingOffset`

Starting offset of the byte range.

### `Length`

Size, in bytes, of the range. If this member is HTTP_BYTE_RANGE_TO_EOF, the range extends from the starting offset to the end of the file or data block.

## See also

[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk)

[HttpReadFragmentFromCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreadfragmentfromcache)