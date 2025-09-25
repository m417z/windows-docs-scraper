# WebSocketCompleteAction function

## Description

The **WebSocketCompleteAction** function completes an action started by [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction).

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

WebSocket session handle returned by a previous call to [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) or [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `pvActionContext` [in]

Type: **PVOID**

Pointer to an action context handle that was returned by a previous call to [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction).

### `ulBytesTransferred` [in]

Type: **ULONG**

Number of bytes transferred for the [WEB_SOCKET_SEND_TO_NETWORK_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action) or **WEB_SOCKET_RECEIVE_FROM_NETWORK_ACTION** actions. This value must be 0 for all other actions.

## Return value

If the function succeeds, it returns **S_OK**.

If the function fails, it returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

## Remarks

Each call to [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction) must be paired with a call to **WebSocketCompleteAction**. For the following network actions, I/O errors can occur:

* [WEB_SOCKET_SEND_TO_NETWORK_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action): if *ulBytesTransferred* is different than the sum all buffer lengths returned from [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction) the current send action is canceled and the next call to **WebSocketGetAction** will return **WEB_SOCKET_INDICATE_SEND_COMPLETE_ACTION** even if not all buffers passed to [WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend) were processed.
* [WEB_SOCKET_RECEIVE_FROM_NETWORK_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action): if *ulBytesTransferred* is 0, the current receive action is canceled and the next call to [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction) will return **WEB_SOCKET_INDICATE_RECEIVE_COMPLETE_ACTION** even if not all buffers passed to [WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive) were processed.

## See also

[WEB_SOCKET_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action)

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction)