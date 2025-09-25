# WebSocketEndServerHandshake function

## Description

The **WebSocketEndServerHandshake** function completes the server-side handshake.

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

 WebSocket session handle returned by a previous call to [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

## Remarks

This function may be called to complete the server-side handshake after a previous call to [WebSocketBeginServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginserverhandshake); however, calling this function is optional and applications may use the session functions without first calling this function. This function frees all internal handshake related structures and allocates data session buffers. All operations handled by this function will be performed internally even if the function is not called.

## See also

[WebSocketBeginClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginclienthandshake)

[WebSocketBeginServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginserverhandshake)

[WebSocketEndClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendclienthandshake)