# WEB_SOCKET_HTTP_HEADER structure

## Description

The **WEB_SOCKET_HTTP_HEADER** structure contains an HTTP header.

## Members

### `pcName`

Type: **PCHAR**

A pointer to the HTTP header name. The name must not contain a colon character.

### `ulNameLength`

Type: **ULONG**

Length, in characters, of the HTTP header pointed to by **pcName**.

### `pcValue`

Type: **PCHAR**

A pointer to the HTTP header value.

### `ulValueLength`

Type: **ULONG**

Length, in characters, of the HTTP value pointed to by **pcValue**.

## See also

[WebSocketBeginClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginclienthandshake)

[WebSocketBeginServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginserverhandshake)

[WebSocketEndClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendclienthandshake)

[WebSocketEndServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendserverhandshake)