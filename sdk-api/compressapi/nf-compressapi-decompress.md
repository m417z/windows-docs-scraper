# Decompress function

## Description

Takes a block of compressed information and decompresses it.

## Parameters

### `DecompressorHandle` [in]

Handle to a decompressor returned by [CreateDecompressor](https://learn.microsoft.com/windows/desktop/api/compressapi/nf-compressapi-createdecompressor).

### `CompressedData` [in]

Contains the block of information that is to be decompressed. The size in bytes of the compressed block is given by *CompressedDataSize*.

### `CompressedDataSize` [in]

The size in bytes of the compressed information.

### `UncompressedBuffer` [out]

The buffer that receives the uncompressed information. The size in bytes of the buffer is given by *UncompressedBufferSize*.

### `UncompressedBufferSize` [in]

Size in bytes of the buffer that receives the uncompressed information.

### `UncompressedDataSize` [out]

Actual size in bytes of the uncompressed information received.

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the block of compressed data pointed to by *CompressedData* is corrupted, the function can fail and the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_BAD_COMPRESSION_BUFFER**. It is also possible that the function will produce a block of uncompressed data that does not match the original data.

It is recommended that compressors and decompressors not use the **COMPRESS_RAW** flag. If the compressor is created with the **COMPRESS_RAW** flag, the decompressor must also be created with the **COMPRESS_RAW** flag.

 If the compressor and decompressor are created using the **COMPRESS_RAW** flag, the value of *UncompressedBufferSize* must be exactly equal to the original size of the uncompressed data and not just the size of the output buffer. This means you should save the exact original size of the uncompressed data, as well as the compressed data and compressed size, when using the **COMPRESS_RAW** flag. If *UncompressedBufferSize* does not equal the original size of the uncompressed data, the uncompressed data will not match the original data. In this case, the function can return success or it can return **ERROR_BAD_COMPRESSION_BUFFER**.

If the **COMPRESS_RAW** flag is not used, *UncompressedBufferSize* is not required to be exactly equal to the original size of the uncompressed data. In this case, *UncompressedDataSize* returns the original size of the uncompressed data. If *UncompressedBufferSize* is smaller than the original data size, the function will fail and set *UncompressedDataSize* to the size of the original data and the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is **ERROR_INSUFFICIENT_BUFFER**.

To determine how large the *UncompressedBuffer* needs to be, call the function with *UncompressedBufferSize* set to zero. In this case, the function will fail and set *UncompressedDataSize* to the size of the original data and the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is **ERROR_INSUFFICIENT_BUFFER**. Note that the original size returned by the function is extracted from the buffer itself and should be treated as untrusted and tested against reasonable limits.

If the function is called with the *CompressedDataSize* parameter set to zero, the function fails and the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is **ERROR_INSUFFICIENT_BUFFER**. When it fails the function returns with *UncompressedDataSize* set to a value that you can use to avoid allocating too large a buffer for the compressed data. You must know the maximum possible size of the original data to use this method.

If you set *CompressedDataSize* to zero, and set *UncompressedBufferSize* to the maximum possible size of the original uncompressed data, the **Decompress** function will fail as described and the value of *UncompressedDataSize* will be set to the maximum size for the compressed data buffer.

If the compression algorithm fails for some internal reason, the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_FUNCTION_FAILED**. If the system cannot locate the compression algorithm handle, the error can be **ERROR_INVALID_HANDLE**. If the output buffer is too small to hold the uncompressed data, the error can be **ERROR_INSUFFICIENT_BUFFER**.

## See also

[Compression API Functions](https://learn.microsoft.com/windows/desktop/cmpapi/compression-api-functions)