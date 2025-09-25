# InternetTimeFromSystemTimeW function

## Description

Formats a date and time according to the HTTP version 1.0 specification.

## Parameters

### `pst` [in]

Pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date and time to format.

### `dwRFC` [in]

RFC format used. Currently, the only valid format is INTERNET_RFC1123_FORMAT.

### `lpszTime` [out]

Pointer to a string buffer that receives the formatted date and time. The buffer should be of size INTERNET_RFC1123_BUFSIZE.

### `cbTime` [in]

Size of the
*lpszTime* buffer, in bytes.

## Return value

Returns TRUE if the function succeeds, or FALSE otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetTimeFromSystemTime as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)