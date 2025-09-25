# WinHttpWebSocketQueryCloseStatus function

## Description

The **WinHttpWebSocketQueryCloseStatus** function retrieves the close status sent by a server.

## Parameters

### `hWebSocket` [in]

Type: **HINTERNET**

Handle to a WebSocket

### `pusStatus` [out]

Type: **USHORT***

A pointer to a close status code that will be filled upon return. See [WINHTTP_WEB_SOCKET_CLOSE_STATUS](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_close_status) for possible values.

### `pvReason` [out]

Type: **PVOID**

A pointer to a buffer that will receive a close reason on return.

### `dwReasonLength` [in]

Type: **DWORD**

The length of the *pvReason* buffer, in bytes.

### `pdwReasonLengthConsumed` [out]

Type: **DWORD***

The number of bytes consumed. If *pvReason* is **NULL** and *dwReasonLength* is 0, *pdwReasonLengthConsumed* will contain the size of the buffer that needs to be allocated by the calling application.

## Return value

Type: **DWORD**

**NO_ERROR** on success. Otherwise an error code.

|  | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | There is not enough space in *pvReason* to write the whole close reason. |
| **ERROR_INVALID_OPERATION** | No close frame has been received yet. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. |

## Remarks

Call **WinHttpWebSocketQueryCloseStatus** only after [WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose) succeeds or if [WinHttpWebSocketReceive](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketreceive) returns **WINHTTP_WEB_SOCKET_CLOSE_BUFFER_TYPE**.

*pdwReasonLengthConsumed* will never be greater than 123, so allocating buffer with at least 123 will guarantee that **ERROR_INSUFFICIENT_BUFFER** will never be returned.

## See also

[WINHTTP_WEB_SOCKET_CLOSE_STATUS](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_close_status)

[WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose)

[WinHttpWebSocketReceive](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketreceive)