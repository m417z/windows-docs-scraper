# WEB_SOCKET_PROPERTY structure

## Description

The **WEB_SOCKET_PROPERTY** structure contains a single WebSocket property.

## Members

### `Type`

Type: **[WEB_SOCKET_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_property_type)**

The WebSocket property type.

### `pvValue`

Type: **PVOID**

A pointer to the value to set. The pointer must have an alignment compatible with the type of the property.

### `ulValueSize`

Type: **ULONG**

The size, in bytes, of the property pointed to by **pvValue**.

## See also

[WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle)

[WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle)

[WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive)

[WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend)