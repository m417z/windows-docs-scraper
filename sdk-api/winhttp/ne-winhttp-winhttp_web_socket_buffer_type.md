# WINHTTP_WEB_SOCKET_BUFFER_TYPE enumeration

## Description

The **WINHTTP_WEB_SOCKET_BUFFER_TYPE** enumeration includes types of WebSocket buffers.

## Constants

### `WINHTTP_WEB_SOCKET_BINARY_MESSAGE_BUFFER_TYPE:0`

Buffer contains either the entire binary message or the last part of it.

### `WINHTTP_WEB_SOCKET_BINARY_FRAGMENT_BUFFER_TYPE:1`

Buffer contains only part of a binary message.

### `WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE:2`

Buffer contains either the entire UTF-8 message or the last part of it.

### `WINHTTP_WEB_SOCKET_UTF8_FRAGMENT_BUFFER_TYPE:3`

Buffer contains only part of a UTF-8 message.

### `WINHTTP_WEB_SOCKET_CLOSE_BUFFER_TYPE:4`

The server sent a close frame.