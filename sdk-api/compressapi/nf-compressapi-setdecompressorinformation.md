# SetDecompressorInformation function

## Description

Sets information in a decompressor for a particular compression algorithm.

## Parameters

### `DecompressorHandle` [in]

Handle to the decompressor.

### `CompressInformationClass` [in]

A value that identifies the type of information. of the enumeration that identifies the type of information.

### `CompressInformation` [in]

The information being set read as bytes. The maximum size in bytes is given by *CompressInformationSize*.

### `CompressInformationSize` [in]

Maximum size of the information in bytes.

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the compression algorithm fails for some internal reason, the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_FUNCTION_FAILED**. If the system cannot locate the compression algorithm handle, the error can be **ERROR_INVALID_HANDLE**. If the compression algorithm does not allow changing the value of this information class, the error can be **ERROR_NOT_SUPPORTED**. If the compression algorithm does not allow the information class, the error can be **ERROR_UNSUPPORTED_TYPE**.

## See also

[Compression API Functions](https://learn.microsoft.com/windows/desktop/cmpapi/compression-api-functions)