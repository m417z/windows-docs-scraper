# DSTORAGE_SOURCE_FILE structure (dstorage.h)

Describes a source for a request with *SourceType* [DSTORAGE_REQUEST_SOURCE_FILE](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_request_source_type).

## Members

`Source`

The file to perform this read request from.

`Offset`

The offset, in bytes, in the file to start the read request at.

`Size`

Number of bytes to read from the file.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |