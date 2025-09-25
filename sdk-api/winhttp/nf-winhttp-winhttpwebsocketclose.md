# WinHttpWebSocketClose function

## Description

The **WinHttpWebSocketClose** function closes a WebSocket connection.

## Parameters

### `hWebSocket` [in]

Type: **HINTERNET**

Handle to a WebSocket.

**Note** **WinHttpWebSocketClose** does not close this handle. To close the handle, call [WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle) on *hWebSocket* once it is no longer needed.

### `usStatus` [in]

Type: **USHORT**

A close status code. See [WINHTTP_WEB_SOCKET_CLOSE_STATUS](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_close_status) for possible values.

### `pvReason` [in, optional]

Type: **PVOID**

A detailed reason for the close.

### `dwReasonLength` [in]

Type: **DWORD**

The length of *pvReason*, in bytes.

If *pvReason* is NULL, this must be 0. This value must be within the range of 0 to 123.

## Return value

Type: **DWORD**

With the following exception, all error codes indicate that the underlying TCP connection has been aborted.

|  | Description |
| --- | --- |
| **ERROR_INVALID_OPERATION** | A close or send is pending. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. |
| **ERROR_INVALID_SERVER_RESPONSE** | Invalid data was received from the server. |

## Remarks

**WinHttpWebSocketClose** completely closes a WebSocket connection. To close the send channel while still leaving the receive channel open, use [WinHttpWebSocketShutdown](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketshutdown).

It is possible to receive a close frame during regular receive operations. In this case, **WinHttpWebSocketClose** will also send a close frame.

The close timer can be set by the property
[WINHTTP_OPTION_WEB_SOCKET_CLOSE_TIMEOUT](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags).
The default is 10 seconds.

## See also

[WINHTTP_WEB_SOCKET_CLOSE_STATUS](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_close_status)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpWebSocketShutdown](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketshutdown)