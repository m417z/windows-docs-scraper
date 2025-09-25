# WEB_SOCKET_PROPERTY_TYPE enumeration

## Description

The **WEB_SOCKET_PROPERTY_TYPE** enumeration specifies a WebSocket property type.

## Constants

### `WEB_SOCKET_RECEIVE_BUFFER_SIZE_PROPERTY_TYPE:0`

Property type: **ULONG**

The WebSocket property is the internal receive buffer size. The buffer cannot be smaller than 256 bytes.

The default is 4096.

Used with [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) and [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `WEB_SOCKET_SEND_BUFFER_SIZE_PROPERTY_TYPE:1`

Property type: **ULONG**

The WebSocket property is the internal send buffer size. The buffer cannot be smaller than 256 bytes.

The default is 4096 on a handle created with [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle), and 16 on a handle created with [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

Used with [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) and [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `WEB_SOCKET_DISABLE_MASKING_PROPERTY_TYPE:2`

Property type: **BOOL**

The WebSocket property is the disabling of the mask bit in client frames. On the client, this property sets the mask key to 0. On the server, this property allows the server to accept client frames with the mask bit set to 0. This property may have serious security implications.
By default, this property is not used and masking is enabled.

Used with [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) and [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `WEB_SOCKET_ALLOCATED_BUFFER_PROPERTY_TYPE:3`

Property type: **PVOID**

The WebSocket property is the buffer that is used as an internal buffer. If the passed buffer is not used, the WebSocket library will take care of buffer management.
The passed buffer must be aligned to an 8-byte boundary and be greater in size than the receive buffer size + send buffer size + 256 bytes.

Used with [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) and [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `WEB_SOCKET_DISABLE_UTF8_VERIFICATION_PROPERTY_TYPE:4`

Property type: **BOOL**

The WebSocket property disables UTF-8 verification.

Used with [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle) and [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `WEB_SOCKET_KEEPALIVE_INTERVAL_PROPERTY_TYPE:5`

Property type: **ULONG**

The WebSocket property is the interval, in milliseconds, to send a keep-alive packet over the connection. The default interval is 30000 (30 seconds). The minimum interval is 15000 (15 seconds).

**Note** The default value for the keep-alive interval is read from **HKLM:\SOFTWARE\Microsoft\WebSocket\KeepaliveInterval**. If a value is not set, the default value of 30000 will be used. It is not possible to have a lower keepalive interval than 15000 milliseconds. If a lower value is set, 15000 milliseconds will be used.

Used with [WebSocketGetGlobalProperty](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetglobalproperty).

### `WEB_SOCKET_SUPPORTED_VERSIONS_PROPERTY_TYPE:6`

Property type: **ULONG** array

The WebSocket property is the versions of the WebSocket protocol that are supported.

Used with [WebSocketGetGlobalProperty](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetglobalproperty).

## See also

[WEB_SOCKET_PROPERTY](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_property)

[WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive)

[WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend)