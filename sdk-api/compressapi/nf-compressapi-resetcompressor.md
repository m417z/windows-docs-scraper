# ResetCompressor function

## Description

Prepares the compressor for the compression of a new stream. The compressor object retains properties set with [SetCompressorInformation](https://learn.microsoft.com/windows/desktop/api/compressapi/nf-compressapi-setcompressorinformation). The sequence of blocks generated is independent of previous blocks.

## Parameters

### `CompressorHandle` [in]

Handle to the compressor returned by [CreateCompressor](https://learn.microsoft.com/windows/desktop/api/compressapi/nf-compressapi-createcompressor).

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the compression algorithm fails for some internal reason, the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_FUNCTION_FAILED**. If the system cannot locate the compression algorithm handle, the error can be **ERROR_INVALID_HANDLE**.

## See also

[Compression API Functions](https://learn.microsoft.com/windows/desktop/cmpapi/compression-api-functions)