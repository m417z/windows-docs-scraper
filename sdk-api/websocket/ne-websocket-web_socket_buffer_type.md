# WEB_SOCKET_BUFFER_TYPE enumeration

## Description

The **WEB_SOCKET_BUFFER_TYPE** enumeration specifies the bit values used to construct the WebSocket frame header.

## Constants

### `WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE:0x80000000`

Indicates the buffer contains the last, and possibly only, part of a UTF8 message.

### `WEB_SOCKET_UTF8_FRAGMENT_BUFFER_TYPE:0x80000001`

Indicates the buffer contains part of a UTF8 message.

### `WEB_SOCKET_BINARY_MESSAGE_BUFFER_TYPE:0x80000002`

Indicates the buffer contains the last, and possibly only, part of a binary message.

### `WEB_SOCKET_BINARY_FRAGMENT_BUFFER_TYPE:0x80000003`

Indicates the buffer contains part of a binary message.

### `WEB_SOCKET_CLOSE_BUFFER_TYPE:0x80000004`

Indicates the buffer contains a close message.

### `WEB_SOCKET_PING_PONG_BUFFER_TYPE:0x80000005`

Indicates the buffer contains a ping or pong message. When sending, this value means 'ping', when processing received data, this value means 'pong'.

### `WEB_SOCKET_UNSOLICITED_PONG_BUFFER_TYPE:0x80000006`

Indicates the buffer contains an unsolicited pong message.

## Remarks

Please note that the *FRAGMENT* and *MESSAGE* buffer types may not correspond to how the message appears (or is framed) on the wire. For example, when a single unfragmented 1000-byte message is received, WebSocket.dll may return multiple *FRAGMENT* buffer types followed by a single *MESSAGE* buffer type (with the sizes adding up to 1000).

Extension WebSocket frame headers (allowing reserved bits to be set by extensions) may be constructed by setting the high bit (MSB) and low bit (LSB) to 0. The remaining 9 lowest bits can then be used to form the custom frame header in place of the **WEB_SOCKET_BUFFER_TYPE** enumeration values.

## See also

[WebSocketGetAction](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketgetaction)

[WebSocketReceive](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketreceive)

[WebSocketSend](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketsend)