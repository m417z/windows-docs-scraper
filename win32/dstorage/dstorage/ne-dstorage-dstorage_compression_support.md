# DSTORAGE_COMPRESSION_SUPPORT enumeration (dstorage.h)

Defines constants that specify features used by the runtime to decompress content. Returned by [IDStorageQueue2::GetCompressionSupport](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue2-getcompressionsupport).

## Constants

|   |
| ---- |
| `DSTORAGE_COMPRESSION_FORMAT_NONE` <br> Specifies no support.|
| `DSTORAGE_COMPRESSION_SUPPORT_GPU_OPTIMIZED` <br> Specifies optimized driver support for GPU decompression.|
| `DSTORAGE_COMPRESSION_SUPPORT_GPU_FALLBACK` <br> Specifies the built-in GPU decompression fallback shader. This can apply if optimized driver support isn't available and the D3D12 device used for this DirectStorage queue supports the required capabilities.|
| `DSTORAGE_COMPRESSION_SUPPORT_CPU_FALLBACK` <br> Specifies a CPU fallback implementation. This can apply if: optimized driver support and built-in GPU decompression isn't available; or GPU decompression support has been explicitly disabled using **DSTORAGE_CONFIGURATION**; or the DirectStorage runtime encounters a failure during initialization of its GPU decompression system..|
| `DSTORAGE_COMPRESSION_SUPPORT_USES_COMPUTE_QUEUE` <br> Specifies that work executes on a compute queue.|
| `DSTORAGE_COMPRESSION_SUPPORT_USES_COPY_QUEUE` <br> Specifies that work executes on a copy queue.|

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |