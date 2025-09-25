# WinHttpWebSocketSend function

## Description

The **WinHttpWebSocketSend** function sends data over a WebSocket connection.

## Parameters

### `hWebSocket` [in]

Type: **HINTERNET**

Handle to a websocket.

### `eBufferType` [in]

Type: **[WINHTTP_WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_buffer_type)**

Type of buffer.

**Note** Do not specify **WINHTTP_WEB_SOCKET_CLOSE_BUFFER_TYPE**. Use [WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose) or [WinHttpWebSocketShutdown](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketshutdown) to close the connection.

### `pvBuffer` [in]

Type: **PVOID**

Pointer to a buffer containing the data to send. Can be **NULL** only if *dwBufferLength* is 0.

### `dwBufferLength` [in]

Type: **DWORD**

Length of *pvBuffer*.

## Return value

Type: **DWORD**

**NO_ERROR** on success. Otherwise an error code.

|  | Description |
| --- | --- |
| **ERROR_INVALID_OPERATION** | A close or send is pending, or the send channel has already been closed. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. |

## See also

[WINHTTP_WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_buffer_type)