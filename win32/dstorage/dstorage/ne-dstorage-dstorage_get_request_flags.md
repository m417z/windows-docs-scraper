# DSTORAGE_GET_REQUEST_FLAGS enumeration (dstorage.h)

Defines constants that specify a type of custom decompression request. Used with [**IDStorageCustomDecompressionQueue1::GetRequests1**](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragecustomdecompressionqueue1-getrequests1) when requesting items from the custom decompression queue.

## Constants

|   |
| ---- |
| `DSTORAGE_GET_REQUEST_FLAG_SELECT_CUSTOM` <br> Specifies a request for entries that use custom decompression formats greater than or equal to [**DSTORAGE_CUSTOM_COMPRESSION_0**](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_compression_format).|
| `DSTORAGE_GET_REQUEST_FLAG_SELECT_BUILTIN` <br> Specifies a request for entries that use built-in compression formats that DirectStorage understands.|
| `DSTORAGE_GET_REQUEST_FLAG_SELECT_ALL` <br> Specifies a request for all entries. This includes custom decompression and built-in compressed formats.|

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |