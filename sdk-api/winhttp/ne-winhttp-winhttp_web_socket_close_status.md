# WINHTTP_WEB_SOCKET_CLOSE_STATUS enumeration

## Description

The **WINHTTP_WEB_SOCKET_CLOSE_STATUS** enumeration includes the status of a WebSocket close operation.

## Constants

### `WINHTTP_WEB_SOCKET_SUCCESS_CLOSE_STATUS:1000`

The connection closed successfully.

### `WINHTTP_WEB_SOCKET_ENDPOINT_TERMINATED_CLOSE_STATUS:1001`

The peer is going away and terminating the connection.

### `WINHTTP_WEB_SOCKET_PROTOCOL_ERROR_CLOSE_STATUS:1002`

A protocol error occurred.

### `WINHTTP_WEB_SOCKET_INVALID_DATA_TYPE_CLOSE_STATUS:1003`

Invalid data received by the peer.

### `WINHTTP_WEB_SOCKET_EMPTY_CLOSE_STATUS:1005`

The close message was empty.

### `WINHTTP_WEB_SOCKET_ABORTED_CLOSE_STATUS:1006`

The connection was aborted.

### `WINHTTP_WEB_SOCKET_INVALID_PAYLOAD_CLOSE_STATUS:1007`

The payload was invalid.

### `WINHTTP_WEB_SOCKET_POLICY_VIOLATION_CLOSE_STATUS:1008`

The message violates an endpoint's policy.

### `WINHTTP_WEB_SOCKET_MESSAGE_TOO_BIG_CLOSE_STATUS:1009`

The message sent was too large to process.

### `WINHTTP_WEB_SOCKET_UNSUPPORTED_EXTENSIONS_CLOSE_STATUS:1010`

A client endpoint expected the server to negotiate one or more extensions, but the server didn't return them in the response message of the WebSocket handshake.

### `WINHTTP_WEB_SOCKET_SERVER_ERROR_CLOSE_STATUS:1011`

An unexpected condition prevented the server from
fulfilling the request.

### `WINHTTP_WEB_SOCKET_SECURE_HANDSHAKE_ERROR_CLOSE_STATUS:1015`

The TLS handshake could not be completed.

#### - WINHTTP_WEB_SOCKET_INVALID_UTF8_CLOSE_STATUS

UTF-8 frame carried an invalid UTF-8 stream.

## Remarks

**WINHTTP_WEB_SOCKET_CLOSE_STATUS** is used by [WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose), [WinHttpWebSocketShutdown](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketshutdown), and [WinHttpWebSocketQueryCloseStatus](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketqueryclosestatus).

## See also

[WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose)

[WinHttpWebSocketQueryCloseStatus](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketqueryclosestatus)

[WinHttpWebSocketShutdown](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketshutdown)