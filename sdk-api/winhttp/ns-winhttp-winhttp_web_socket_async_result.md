# WINHTTP_WEB_SOCKET_ASYNC_RESULT structure

## Description

 The **WINHTTP_WEB_SOCKET_ASYNC_RESULT** includes the result status of a WebSocket operation.

## Members

### `AsyncResult`

Type: **[WINHTTP_ASYNC_RESULT](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_async_result)**

The result of a WebSocket operation.

### `Operation`

Type: **[WINHTTP_WEB_SOCKET_OPERATION](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_operation)**

The type of WebSocket operation.

## Remarks

A **WINHTTP_WEB_SOCKET_ASYNC_RESULT** structure is passed to the completion callbacks of WebSocket functions such as [WinHttpWebSocketSend](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketsend), [WinHttpWebSocketReceive](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketreceive), and [WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose) when *dwInternetStatus* is **WINHTTP_CALLBACK_STATUS_REQUEST_ERROR**.

## See also

[WINHTTP_ASYNC_RESULT](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_async_result)

[WINHTTP_WEB_SOCKET_OPERATION](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_operation)

[WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose)

[WinHttpWebSocketReceive](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketreceive)

[WinHttpWebSocketSend](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketsend)

[WinHttpWebSocketShutdown](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketshutdown)