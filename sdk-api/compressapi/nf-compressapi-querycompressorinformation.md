# QueryCompressorInformation function

## Description

Queries a compressor for information for a particular compression algorithm.

## Parameters

### `CompressorHandle` [in]

Handle to the compressor being queried for information.

### `CompressInformationClass` [in]

A value of the [COMPRESS_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/compressapi/ne-compressapi-compress_information_class) enumeration that identifies the type of information.

### `CompressInformation` [out]

Information for the compression algorithm written as bytes. The maximum size in bytes of this information is given by *CompressInformationSize*.

### `CompressInformationSize` [in]

Maximum size in bytes of the information.

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the compression algorithm fails for some internal reason, the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_FUNCTION_FAILED**. If the system cannot locate the compression algorithm handle, the error can be **ERROR_INVALID_HANDLE**. If the compression algorithm does not allow the information class, the error can be **ERROR_UNSUPPORTED_TYPE**. If the buffer is too small to hold the value, the error can be **ERROR_INSUFFICIENT_BUFFER**.

## See also

[Compression API Functions](https://learn.microsoft.com/windows/desktop/cmpapi/compression-api-functions)