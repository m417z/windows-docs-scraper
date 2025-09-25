# WEB_SOCKET_CLOSE_STATUS enumeration

## Description

The **WEB_SOCKET_CLOSE_STATUS** enumeration specifies the WebSocket close status as defined by [WSPROTO](https://datatracker.ietf.org/doc/html/rfc6455).

## Constants

### `WEB_SOCKET_SUCCESS_CLOSE_STATUS:1000`

Close completed successfully.

### `WEB_SOCKET_ENDPOINT_UNAVAILABLE_CLOSE_STATUS:1001`

The endpoint is going away and thus closing the connection.

### `WEB_SOCKET_PROTOCOL_ERROR_CLOSE_STATUS:1002`

Peer detected protocol error and it is closing the connection.

### `WEB_SOCKET_INVALID_DATA_TYPE_CLOSE_STATUS:1003`

The endpoint cannot receive this type of data.

### `WEB_SOCKET_EMPTY_CLOSE_STATUS:1005`

No close status
code was provided.

### `WEB_SOCKET_ABORTED_CLOSE_STATUS:1006`

The
connection was closed without sending or
receiving a close frame.

### `WEB_SOCKET_INVALID_PAYLOAD_CLOSE_STATUS:1007`

Data within a message is not consistent with the type of the message.

### `WEB_SOCKET_POLICY_VIOLATION_CLOSE_STATUS:1008`

The message violates an endpoint's policy.

### `WEB_SOCKET_MESSAGE_TOO_BIG_CLOSE_STATUS:1009`

The message sent was too large to process.

### `WEB_SOCKET_UNSUPPORTED_EXTENSIONS_CLOSE_STATUS:1010`

A client endpoint expected the server to negotiate one or more extensions, but the server didn't return them in the response message of the WebSocket handshake.

### `WEB_SOCKET_SERVER_ERROR_CLOSE_STATUS:1011`

An unexpected condition prevented the server from
fulfilling the request.

### `WEB_SOCKET_SECURE_HANDSHAKE_ERROR_CLOSE_STATUS:1015`

The
TLS handshake could not be completed.

## See also

[WEB_SOCKET_BUFFER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_buffer)