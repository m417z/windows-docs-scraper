# WebSocketReceive function

## Description

The **WebSocketReceive** function adds a receive operation to the protocol component operation queue.

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

WebSocket session handle returned by a previous call to [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) or [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `pBuffer` [in, optional]

Type: **[WEB_SOCKET_BUFFER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_buffer)***

A pointer to an array of [WEB_SOCKET_BUFFER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_buffer) structures that WebSocket data will be written to when it is returned by [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction). If **NULL**, **WebSocketGetAction** will return an internal buffer that enables zero-copy scenarios.

**Note** Once [WEB_SOCKET_INDICATE_RECEIVE_COMPLETE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_property_type) is returned by [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction) for this action, the memory pointer to by *pBuffer* can be reclaimed.

### `pvContext` [in, optional]

Type: **PVOID**

A pointer to an application context handle that will be returned by a subsequent call to [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction).

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns one of the following or a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

| Return code | Description |
| --- | --- |
| **E_INVALID_PROTOCOL_OPERATION** | Protocol performed an invalid operation. |

## See also

[WEB_SOCKET_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action)

[WebSocketAbortHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketaborthandle)

[WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction)

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction)

[WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend)