# HTTP_DATA_CHUNK structure

## Description

The **HTTP_DATA_CHUNK** structure represents an individual block of data either in memory, in a file, or in the HTTP Server API response-fragment cache.

## Members

### `DataChunkType`

Type of data store. This member can be one of the values from the **HTTP_DATA_CHUNK_TYPE** enumeration.

### `FromMemory`

### `FromMemory.pBuffer`

Pointer to the starting memory address of the data block.

### `FromMemory.BufferLength`

Length, in bytes, of the data block.

### `FromFileHandle`

### `FromFileHandle.ByteRange`

An
[HTTP_BYTE_RANGE](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_byte_range) structure that specifies all or part of the file. To specify the entire file, set the **StartingOffset** member to zero and the **Length** member to **HTTP_BYTE_RANGE_TO_EOF**.

### `FromFileHandle.FileHandle`

Open handle to the file in question.

### `FromFragmentCache`

### `FromFragmentCache.FragmentNameLength`

Length, in bytes, of the fragment name not including the terminating null character.

### `FromFragmentCache.pFragmentName`

Pointer to a string that contains the fragment name assigned when the fragment was added to the response-fragment cache using
the [HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache) function.

### `FromFragmentCacheEx`

### `FromFragmentCacheEx.ByteRange`

An [HTTP_BYTE_RANGE](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_byte_range) structure specifying the byte range in the cached fragment.

### `FromFragmentCacheEx.pFragmentName`

Pointer to a string that contains the fragment name assigned when the fragment was added to the response-fragment cache using
the [HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache) function. The length of the string cannot exceed 65532 bytes.

**Note** This string must be NULL terminated.

### `Trailers`

### `Trailers.TrailerCount`

Count of the number of [HTTP_UNKNOWN_HEADER](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_unknown_header) structures in the array pointed to by **pTrailers**.

### `Trailers.pTrailers`

Pointer to an array of [HTTP_UNKNOWN_HEADER](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_unknown_header) structures containing the trailers.

## See also

[HTTP Server API Version 1.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-structures)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response)

[HttpAddFragmentToCache](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddfragmenttocache)

[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody)