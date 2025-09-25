# Compress function

## Description

Takes a block of information and compresses it.

## Parameters

### `CompressorHandle` [in]

Handle to a compressor returned by [CreateCompressor](https://learn.microsoft.com/windows/desktop/api/compressapi/nf-compressapi-createcompressor).

### `UncompressedData` [in]

Contains the block of information that is to be compressed. The size in bytes of the uncompressed block is given by *UncompressedDataSize*.

### `UncompressedDataSize` [in]

Size in bytes of the uncompressed information.

### `CompressedBuffer` [out]

The buffer that receives the compressed information. The maximum size in bytes of the buffer is given by *CompressedBufferSize*.

### `CompressedBufferSize` [in]

Maximum size in bytes of the buffer that receives the compressed information.

### `CompressedDataSize` [out]

Actual size in bytes of the compressed information received.

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the compression algorithm fails for some internal reason, the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_FUNCTION_FAILED**. If the system cannot locate the compression algorithm handle, the error can be **ERROR_INVALID_HANDLE**. If the output buffer is too small to hold the compressed data, the error can be **ERROR_INSUFFICIENT_BUFFER**.

If *CompressedBuffer* output buffer is too small to hold the compressed data, the function fails and the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_INSUFFICIENT_BUFFER**. In this case, the *CompressedDataSize* parameter receives with the size that the *CompressedBuffer* needs to be to guarantee success for that input buffer. You can set *CompressedBufferSize* to zero to determine the size of the output buffer to allocate.

## See also

[Compression API Functions](https://learn.microsoft.com/windows/desktop/cmpapi/compression-api-functions)