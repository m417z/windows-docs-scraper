# DSTORAGE_COMPRESSION_FORMAT enumeration (dstorage.h)

Defines constants that specify the type of compression format used at the decompression stage. Your application can implement custom decompressors, starting from **DSTORAGE_CUSTOM_COMPRESSION_0**.

## Constants

|   |
| ---- |
| `DSTORAGE_COMPRESSION_FORMAT_NONE` <br> Specifies that the data is uncompressed.|
| `DSTORAGE_COMPRESSION_FORMAT_GDEFLATE` <br> Specifies that the data is compressed using the built-in *GDeflate* format; intended to be decompressed by using the GPU.|
| `DSTORAGE_CUSTOM_COMPRESSION_0` <br> Specifies that the data is stored in an application-defined custom format. Your application must use [IDStorageCustomDecompressionQueue](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nn-dstorage-idstoragecustomdecompressionqueue) to implement custom decompression. You can use additional custom compression formats; for example, `(DSTORAGE_CUSTOM_COMPRESSION_0 + 1)`.|

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |