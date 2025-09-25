# InternetReadFileExW function

## Description

Reads data from a handle opened by the
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla) or
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) function.

## Parameters

### `hFile` [in]

Handle returned by the
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla) or
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) function.

### `lpBuffersOut` [out]

Pointer to an
[INTERNET_BUFFERS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_buffersa) structure that receives the data downloaded.

### `dwFlags` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| IRF_ASYNC | Identical to [WININET_API_FLAG_ASYNC](https://learn.microsoft.com/windows/desktop/WinInet/api-flags). |
| IRF_SYNC | Identical to [WININET_API_FLAG_SYNC](https://learn.microsoft.com/windows/desktop/WinInet/api-flags). |
| IRF_USE_CONTEXT | Identical to [WININET_API_FLAG_USE_CONTEXT](https://learn.microsoft.com/windows/desktop/WinInet/api-flags). |
| IRF_NO_WAIT | Do not wait for data. If there is data available, the function returns either the amount of data requested or the amount of data available (whichever is smaller). |

### `dwContext` [in]

A caller supplied context value used for asynchronous operations.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). An application can also use
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa) when necessary.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetReadFileEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)