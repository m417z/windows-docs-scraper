# WinHttpWebSocketShutdown function

## Description

The **WinHttpWebSocketShutdown** function sends a close frame to a WebSocket server to close the send channel, but leaves the receive channel open.

## Parameters

### `hWebSocket` [in]

Type: **HINTERNET**

Handle to a WebSocket.

**Note** **WinHttpWebSocketShutdown** does not close this handle. To close the handle, call [WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle) on *hWebSocket* once it is no longer needed.

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
| **ERROR_IO_PENDING** | The operation will complete asynchronously. |

## Remarks

**WinHttpWebSocketShutdown** sends a close frame and prevents additional data from being sent over the WebSocket connection. It does not close the receive channel. Use [WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose) when you want to completely close the connection and prevent any subsequent receive operations.

The application is responsible for receiving the close frame from the server (through regular receive operations).

After **WinHttpWebSocketShutdown** is called, the application can call [WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose) if it does not want to receive a close frame on its own and delegate it to the stack.

## See also

[WINHTTP_WEB_SOCKET_CLOSE_STATUS](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_close_status)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose)