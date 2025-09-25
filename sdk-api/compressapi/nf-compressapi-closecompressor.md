# CloseCompressor function

## Description

Call to close an open **COMPRESSOR_HANDLE**.

## Parameters

### `CompressorHandle` [in]

Handle to the compressor to be closed. This is the handle to the compressor that was returned by [CreateCompressor](https://learn.microsoft.com/windows/desktop/api/compressapi/nf-compressapi-createcompressor).

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the compression algorithm fails for some internal reason, the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_FUNCTION_FAILED**. If the system cannot locate the compression algorithm handle, the error can be **ERROR_INVALID_HANDLE**.

## See also

[Compression API Functions](https://learn.microsoft.com/windows/desktop/cmpapi/compression-api-functions)