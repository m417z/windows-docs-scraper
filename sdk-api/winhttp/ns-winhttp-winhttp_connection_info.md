## Description

The **WINHTTP_CONNECTION_INFO** structure contains the source and destination IP address of the request that generated the response.

## Members

### `cbSize`

The size, in bytes, of the **WINHTTP_CONNECTION_INFO** structure.

### `LocalAddress`

A [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structure that contains the local IP address and port of the original request.

### `RemoteAddress`

A [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structure that contains the remote IP address and port of the original request.

## Remarks

When [WinHttpReceiveResponse](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpreceiveresponse) returns, the application can retrieve the source and destination IP address of the request that generated the response. The application calls [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) with the **WINHTTP_OPTION_CONNECTION_INFO** option, and provides the **WINHTTP_CONNECTION_INFO** structure in the *lpBuffer* parameter.

#### Examples

The following code example shows the call to [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption). Winsock2.h must be included before Winhttp.h when using the **WINHTTP_OPTION_CONNECTION_INFO** option.

If the original request was redirected, the **WINHTTP_CONNECTION_INFO** structure contains the IP address and port of the request that resulted from the first non-30X response.

```cpp
WINHTTP_CONNECTION_INFO ConnInfo;
DWORD dwConnInfoSize = sizeof(WINHTTP_CONNECTION_INFO);

WinHttpQueryOption( hRequest,
                    WINHTTP_OPTION_CONNECTION_INFO,
                    &ConnInfo,
                    &dwConnInfoSize);

```