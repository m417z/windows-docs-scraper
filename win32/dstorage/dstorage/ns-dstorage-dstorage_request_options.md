# DSTORAGE_REQUEST_OPTIONS structure (dstorage.h)

Options for a DirectStorage request.

## Members

`CompressionFormat`

A [DSTORAGE_COMPRESSION_FORMAT](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_compression_format) enum value indicating how the data is compressed.

`Reserved1`

Type: **UINT8[7]**

Reserved fields. Must be 0.

`SourceType`

A [DSTORAGE_REQUEST_SOURCE_TYPE](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_request_source_type) enum value indicating whether the source of the request is a file or a block of memory.

`DestinationType`

A [DSTORAGE_REQUEST_DESTINATION_TYPE](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_request_destination_type) enum value indicating the destination of the request. Block of memory, resource.

`Reserved`

Reserved field. Must be 0.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |