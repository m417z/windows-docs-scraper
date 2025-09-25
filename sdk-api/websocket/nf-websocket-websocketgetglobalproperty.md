# WebSocketGetGlobalProperty function

## Description

The **WebSocketGetGlobalProperty** function gets a single WebSocket property.

## Parameters

### `eType` [in]

Type: **[WEB_SOCKET_PROPERTY](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_property)**

A WebSocket property.

### `pvValue` [in, out]

Type: **PVOID**

A pointer to the property value. The pointer must have an alignment compatible with the type of the property.

### `ulSize` [in, out]

Type: **ULONG***

The size, in bytes, of the property pointed to by **pvValue**.

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

## See also

[WEB_SOCKET_PROPERTY](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_property)

[WEB_SOCKET_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_property_type)