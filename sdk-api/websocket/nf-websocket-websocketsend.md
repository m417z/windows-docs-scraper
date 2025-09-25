# WebSocketSend function

## Description

The **WebSocketSend** function adds a send operation to the protocol component operation queue.

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

WebSocket session handle returned by a previous call to [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) or [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `BufferType` [in]

Type: **[WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_buffer_type)**

The type of WebSocket buffer data to send in *pBuffer*.

### `pBuffer` [in, optional]

Type: **[WEB_SOCKET_BUFFER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_buffer)***

A pointer to an array of [WEB_SOCKET_BUFFER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_buffer) structures that contains WebSocket buffer data to send. If *BufferType* is [WEB_SOCKET_PING_PONG_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_buffer_type) or [WEB_SOCKET_UNSOLICITED_PONG_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_buffer_type), *pBuffer* must be **NULL**.

**Note** Once [WEB_SOCKET_INDICATE_SEND_COMPLETE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_property_type) is returned by [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction) for this action, the memory pointer to by *pBuffer* can be reclaimed.

### `Context` [in, optional]

Type: **PVOID**

A pointer to an application context handle that will be returned by a subsequent call to [WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction).

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns one of the following or a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

| Return code | Description |
| --- | --- |
| **E_INVALID_PROTOCOL_OPERATION** | Protocol performed an invalid operation. |

## Remarks

After an application sends a [WEB_SOCKET_CLOSE_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_property_type) WebSocket buffer successfully, it can only send control frames.

## See also

[WEB_SOCKET_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action)

[WebSocketAbortHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketaborthandle)

[WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction)

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction)

[WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive)