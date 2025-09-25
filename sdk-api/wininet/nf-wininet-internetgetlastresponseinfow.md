# InternetGetLastResponseInfoW function

## Description

Retrieves the last error description or server response on the thread calling this function.

## Parameters

### `lpdwError` [out]

Pointer to a variable that receives an error message pertaining to the operation that failed.

### `lpszBuffer` [out]

Pointer to a buffer that receives the error text.

### `lpdwBufferLength` [in, out]

Pointer to a variable that contains the size of the
*lpszBuffer* buffer, in **TCHARs**. When the function returns, this parameter contains the size of the string written to the buffer, not including the terminating zero.

## Return value

Returns **TRUE** if error text was successfully written to the buffer, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the buffer is too small to hold all the error text,
**GetLastError** returns **ERROR_INSUFFICIENT_BUFFER**, and the
*lpdwBufferLength* parameter contains the minimum buffer size required to return all the error text.

## Remarks

The FTP protocols can return additional text information along with most errors. This extended error information can be retrieved by using the
**InternetGetLastResponseInfo** function whenever
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
[ERROR_INTERNET_EXTENDED_ERROR](https://learn.microsoft.com/windows/desktop/WinInet/wininet-errors) (occurring after an unsuccessful function call).

The buffer pointed to by
*lpszBuffer* must be large enough to hold both the error string and a zero terminator at the end of the string. However, note that the value returned in
*lpdwBufferLength* does not include the terminating zero.

**InternetGetLastResponseInfo** can be called multiple times until another function is called on this thread. When another function is called, the internal buffer that is storing the last response information is cleared.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetGetLastResponseInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)