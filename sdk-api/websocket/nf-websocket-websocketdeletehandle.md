# WebSocketDeleteHandle function

## Description

The **WebSocketDeleteHandle** function deletes a WebSocket session handle created by [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) or [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

WebSocket session handle returned by a previous call to [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) or [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

## Return value

If the function succeeds, it returns **S_OK**.

If the function fails, it returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

## Remarks

Any use of a deleted [WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types) session handle may result in an access violation.

Before an application deletes a session handle, it must ensure that all operations have been processed. Applications may use [WebSocketAbortHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketaborthandle) to abort any queued operations before calling **WebSocketDeleteHandle**.

## See also

[WebSocketAbortHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketaborthandle)

[WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle)

[WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle)