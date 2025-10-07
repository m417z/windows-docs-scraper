# DSTORAGE_CUSTOM_DECOMPRESSION_REQUEST structure (dstorage.h)

A custom decompression request. Use [IDStorageCustomDecompressionQueue](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nn-dstorage-idstoragecustomdecompressionqueue) to retrieve these requests.

## Members

`Id`

An identifier provided by DirectStorage. This should be used to identify the request in [DSTORAGE_CUSTOM_DECOMPRESSION_RESULT](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_custom_decompression_result). This identifier is unique among uncompleted requests, but may be reused after a request has completed.

`CompressionFormat`

The compression format. This will be >= [DSTORAGE_CUSTOM_COMPRESSION_0](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_compression_format).

`Reserved`

Reserved for future use.

`Flags`

Flags containing additional details about the decompression request.

`SrcSize`

The size of *SrcBuffer* in bytes.

`SrcBuffer`

The compressed source buffer.

`DstSize`

The size of *DstBuffer* in bytes.

`DstBuffer`

The uncompressed destination buffer. *SrcBuffer* should be decompressed to *DstBuffer*.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |