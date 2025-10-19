# WEB_SOCKET_BUFFER structure

## Description

The **WEB_SOCKET_BUFFER** structure contains data for a specific WebSocket action.

## Members

### `Data`

### `Data.pbBuffer`

Type: **PBYTE**

Pointer to the WebSocket buffer data.

### `Data.ulBufferLength`

Type: **ULONG**

Length, in bytes, of the buffer pointed to by **pbBuffer**.

### `CloseStatus`

### `CloseStatus.pbReason`

Type: **PBYTE**

A point to a UTF-8 string that represents the reason the connection is closed. If **ulReasonLength** is 0, this must be **NULL**.

### `CloseStatus.ulReasonLength`

Type: **ULONG**

Length, in bytes, of the buffer pointed to by **pbReason**. It cannot exceed **WEB_SOCKET_MAX_CLOSE_REASON_LENGTH** (123 bytes).

### `CloseStatus.usStatus`

Type: **USHORT**

[WEB_SOCKET_CLOSE_STATUS](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_close_status) enumeration that specifies the WebSocket status.

## Remarks

Application must use the **Data** struct for all buffer types except **WEB_SOCKET_CLOSE_BUFFER_TYPE**. The **CloseStatus** struct is used for **WEB_SOCKET_CLOSE_BUFFER_TYPE**.

## See also

[WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/websocket/ne-websocket-web_socket_buffer_type)

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction)

[WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive)

[WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend)