# WebSocketCreateServerHandle function

## Description

The **WebSocketCreateServerHandle** function creates a server-side WebSocket session handle.

## Parameters

### `pProperties` [in]

Type: **const [PWEB_SOCKET_PROPERTY](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_property)**

Pointer to an array of [WEB_SOCKET_PROPERTY](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_property) structures that contain WebSocket session-related properties.

### `ulPropertyCount` [in]

Type: **ULONG**

Number of properties in *pProperties*.

### `phWebSocket` [out]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)***

On successful output, pointer to a newly allocated server-side WebSocket session handle.

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

## See also

[WEB_SOCKET_PROPERTY](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_property)

[WebSocketAbortHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketaborthandle)

[WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle)

[WebSocketDeleteHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketdeletehandle)