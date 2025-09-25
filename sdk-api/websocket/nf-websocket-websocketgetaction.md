# WebSocketGetAction function

## Description

The **WebSocketGetAction** function returns an action from a call to [WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend), [WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive) or [WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction).

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

WebSocket session handle returned by a previous call to [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) or [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `eActionQueue` [in]

Type: **[WEB_SOCKET_ACTION_QUEUE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action_queue)**

Enumeration that specifies whether to query the send queue, the receive queue, or both.

### `pDataBuffers` [in, out]

Type: **[WEB_SOCKET_BUFFER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_buffer)***

Pointer to an array of [WEB_SOCKET_BUFFER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_buffer) structures that contain WebSocket buffer data.

**Note** Do not allocate or deallocate memory for [WEB_SOCKET_BUFFER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_buffer) structures, because they will be overwritten by **WebSocketGetAction**. The memory for buffers returned by **WebSocketGetAction** are managed by the library.

### `pulDataBufferCount` [in, out]

Type: **ULONG***

On input, pointer to a value that specifies the number of elements in *pDataBuffers*. On successful output, number of elements that were actually returned in *pDataBuffers*.

### `pAction` [out]

Type: **[WEB_SOCKET_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action)***

On successful output, pointer to a [WEB_SOCKET_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action) enumeration that specifies the action returned from the query to the queue defines in *eActionQueue*.

### `pBufferType` [out]

Type: **[WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_buffer_type)***

On successful output, pointer to a [WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_buffer_type) enumeration that specifies the type of Web Socket buffer data returned in *pDataBuffers*.

### `pvApplicationContext` [out, optional]

Type: **PVOID***

On successful output, pointer to an application context handle. The context returned here was initially passed to [WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend) or [WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive). *pvApplicationContext* is not set if *pAction* is [WEB_SOCKET_NO_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action) or [WEB_SOCKET_SEND_TO_NETWORK_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action) when sending a pong in response to receiving a ping.

### `pvActionContext` [out]

Type: **PVOID***

On successful output, pointer to an action context handle. This handle is passed into a subsequent call [WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction).

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns one of the following or a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

| Return code | Description |
| --- | --- |
| **E_INVALID_PROTOCOL_FORMAT** | Protocol data had invalid format. This is only returned for receive operations. |
| **E_INVALID_PROTOCOL_OPERATION** | Protocol performed invalid operations. This is only returned for receive operations. |

## Remarks

Each call to **WebSocketGetAction** must be paired with a call to [WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction).

If the *ulBytesTransferred* parameter of [WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction) is different than the sum of all buffer lengths for the [WEB_SOCKET_SEND_TO_NETWORK_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action) action or is zero for the **WEB_SOCKET_RECEIVE_FROM_NETWORK_ACTION** action, the WebSocket application will not send or receive all of the data requested.

**WebSocketGetAction** will return in *pAction*:

* [WEB_SOCKET_INDICATE_SEND_COMPLETE_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action) once an operation queued by [WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend) is completed.
* [WEB_SOCKET_INDICATE_RECEIVE_COMPLETE_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action) once an operation queued by [WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive) is completed.

There may be only one outstanding send and receive operation at a time, so the next action will be returned once the previous one has been completed using [WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction).

## See also

[WEB_SOCKET_ACTION](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action)

[WEB_SOCKET_ACTION_QUEUE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_action_queue)

[WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_buffer_type)

[WebSocketCompleteAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcompleteaction)

[WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive)

[WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend)