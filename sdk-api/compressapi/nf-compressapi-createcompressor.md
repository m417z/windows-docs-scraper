# CreateCompressor function

## Description

Generates a new **COMPRESSOR_HANDLE**.

## Parameters

### `Algorithm` [in]

The type of compression algorithm and mode to be used by this compressor.

This parameter can have one of the following values optionally combined with the **COMPRESS_RAW** flag. Use a "bitwise OR" operator to include **COMPRESS_RAW** and to create a block mode compressor. If **COMPRESS_RAW** is not included, the Compression API creates a buffer mode compressor. For more information about selecting a compression algorithm and mode, see [Using the Compression API](https://learn.microsoft.com/windows/desktop/cmpapi/using-the-compression-api).

| Value | Meaning |
| --- | --- |
| **COMPRESS_ALGORITHM_MSZIP**<br><br>2 | MSZIP compression algorithm |
| **COMPRESS_ALGORITHM_XPRESS**<br><br>3 | XPRESS compression algorithm |
| **COMPRESS_ALGORITHM_XPRESS_HUFF**<br><br>4 | XPRESS compression algorithm with Huffman encoding |
| **COMPRESS_ALGORITHM_LZMS**<br><br>5 | LZMS compression algorithm |

### `AllocationRoutines` [in, optional]

Optional memory allocation and deallocation routines in a [COMPRESS_ALLOCATION_ROUTINES](https://learn.microsoft.com/windows/win32/api/compressapi/ns-compressapi-compress_allocation_routines) structure.

### `CompressorHandle` [out]

If the function succeeds, the handle to the specified compressor.

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the compression algorithm fails for some internal reason, the error from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be **ERROR_FUNCTION_FAILED**. If the system can find no compression algorithm matching the specified name and version, the error can be **ERROR_NOT_SUPPORTED**.

## See also

[COMPRESS_ALLOCATION_ROUTINES](https://learn.microsoft.com/windows/win32/api/compressapi/ns-compressapi-compress_allocation_routines)

[Compression API Functions](https://learn.microsoft.com/windows/desktop/cmpapi/compression-api-functions)