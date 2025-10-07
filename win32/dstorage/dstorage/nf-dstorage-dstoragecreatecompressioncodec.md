# DStorageCreateCompressionCodec function (dstorage.h)

Retrieves a DirectStorage object used to compress/decompress content. Compression codecs are not thread safe, so multiple instances are required if the codecs need to be used by multiple threads.

## Parameters

`format`

Type: **[DSTORAGE_COMPRESSION_FORMAT](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_compression_format)**

Specifies how the data is compressed.

`numThreads`

Specifies the maximum number of threads that this codec will use. Specifying 0 means to use the system's best guess at a good value.

`riid`

Specifies the DirectStorage compressor/decompressor interface, such as `__uuidof(IDStorageCompressionCodec)`.

`ppv`

Receives the DirectStorage factory object.

## Return value

Standard HRESULT error code.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |