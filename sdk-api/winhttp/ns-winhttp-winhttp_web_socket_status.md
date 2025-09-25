# WINHTTP_WEB_SOCKET_STATUS structure

## Description

The **WINHTTP_WEB_SOCKET_STATUS** enumeration includes the status of a WebSocket operation.

## Members

### `dwBytesTransferred`

Type: **DWORD**

The amount of bytes transferred in the operation.

### `eBufferType`

Type: **[WINHTTP_WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_buffer_type)**

The type of data in the buffer.

## Remarks

A **WINHTTP_WEB_SOCKET_STATUS** structure is passed to the completion callback of [WinHttpWebSocketSend](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketsend) when *dwInternetStatus* is **WINHTTP_CALLBACK_STATUS_READ_COMPLETE**.

A **WINHTTP_WEB_SOCKET_STATUS** structure is passed to the completion callback of [WinHttpWebSocketReceive](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketreceive) when *dwInternetStatus* is **WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE**.

## See also

[WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback)

[WINHTTP_WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_buffer_type)

[WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose)

[WinHttpWebSocketReceive](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketreceive)

[WinHttpWebSocketSend](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketsend)

[WinHttpWebSocketShutdown](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketshutdown)