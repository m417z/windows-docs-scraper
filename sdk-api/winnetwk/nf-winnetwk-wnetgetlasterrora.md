# WNetGetLastErrorA function

## Description

The
**WNetGetLastError** function retrieves the most recent extended error code set by a WNet function. The network provider reported this error code; it will not generally be one of the errors included in the SDK header file WinError.h.

## Parameters

### `lpError` [out]

Pointer to a variable that receives the error code reported by the network provider. The error code is specific to the network provider.

### `lpErrorBuf` [out]

Pointer to the buffer that receives the null-terminated string describing the error.

### `nErrorBufSize` [in]

Size of the buffer pointed to by the *lpErrorBuf* parameter, in characters. If the buffer is too small for the error string, the string is truncated but still null-terminated. A buffer of at least 256 characters is recommended.

### `lpNameBuf` [out]

Pointer to the buffer that receives the null-terminated string identifying the network provider that raised the error.

### `nNameBufSize` [in]

Size of the buffer pointed to by the *lpNameBuf* parameter, in characters. If the buffer is too small for the error string, the string is truncated but still null-terminated.

## Return value

If the function succeeds, and it obtains the last error that the network provider reported, the return value is NO_ERROR.

If the caller supplies an invalid buffer, the return value is ERROR_INVALID_ADDRESS.

## Remarks

The
**WNetGetLastError** function retrieves errors that are specific to a network provider. You can call
**WNetGetLastError** when a WNet function returns ERROR_EXTENDED_ERROR.

Like the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function,
**WNetGetLastError** returns extended error information, which is maintained on a per-thread basis. Unlike **GetLastError**, the
**WNetGetLastError** function can return a string for reporting errors that are not described by any existing error code in WinError.h.

For more information about using an application-defined error handler that calls the
**WNetGetLastError** function, see
[Retrieving Network Errors](https://learn.microsoft.com/windows/desktop/WNet/retrieving-network-errors).

> [!NOTE]
> The winnetwk.h header defines WNetGetLastError as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)