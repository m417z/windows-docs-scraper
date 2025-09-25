# HttpSendRequestExA function

## Description

Sends the specified request to the HTTP server.

**Note** Callers that need to send extra data beyond what is normally passed to **HttpSendRequestEx** can do so by calling [HttpSendRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequesta) instead.

## Parameters

### `hRequest` [in]

A
handle returned by
a call to the [HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) function.

### `lpBuffersIn` [in]

Optional. A pointer to an
[INTERNET_BUFFERS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_buffersa) structure.

### `lpBuffersOut` [out]

Reserved. Must be **NULL**.

### `dwFlags` [in]

Reserved. Must be zero.

### `dwContext` [in]

Application-defined context value, if a status callback function has been registered.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**HttpSendRequestEx** performs both the send and the receive for the response. This does not allow the application to send any extra data beyond the single buffer that was passed to **HttpSendRequestEx**. Callers that need to send extra data beyond what is normally passed to **HttpSendRequestEx** can do so by calling [HttpSendRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequesta) instead. After the call to **HttpSendRequestEx**, send the remaining data by calling [InternetWriteFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetwritefile). Finally, follow up with a call to [HttpEndRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpendrequesta).

**Note** The **HttpSendRequestExA** function represents data to send as ISO-8859-1 characters not ANSI characters. The **HttpSendRequestExW** function represents data to send as ISO-8859-1 characters converted to UTF-16LE characters. As a result, it is never safe to use the **HttpSendRequestExW** function when the headers to be added can contain non-ASCII characters.
Instead, an application can use the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) and [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) functions with a *Codepage* parameter set to 28591 to map between ANSI characters and UTF-16LE characters.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines HttpSendRequestEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/http-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)