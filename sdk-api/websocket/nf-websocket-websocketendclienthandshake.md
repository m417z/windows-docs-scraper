# WebSocketEndClientHandshake function

## Description

The **WebSocketEndClientHandshake** function completes the client-side handshake.

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

 WebSocket session handle returned by a previous call to [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle).

### `pResponseHeaders` [in]

Type: **const [PWEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header)**

Pointer to an array of [WEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header) structures that contain the response headers received by the application.

### `ulReponseHeaderCount` [in]

Type: **ULONG**

Number of response headers in *pResponseHeaders*.

### `pulSelectedExtensions` [in, out, optional]

Type: **ULONG***

On input, pointer to an array allocated by the application. On successful output, pointer to an array of numbers that represent the extensions chosen by the server during the client-server handshake. These number are the zero-based indices into the extensions array passed to *pszExtensions* in [WebSocketBeginClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginclienthandshake).

### `pulSelectedExtensionCount` [in, out, optional]

Type: **ULONG***

On input, number of extensions allocated in *pulSelectedExtensions*. This must be at least equal to the number passed to *ulExtensionCount* in **WebSocketEndClientHandshake**. On successful output, number of extensions returned in *pulSelectedExtensions*.

### `pulSelectedSubprotocol` [in, out, optional]

Type: **ULONG***

On successful output, pointer to a number that represents the sub-protocol chosen by the server during the client-server handshake. This number is the zero-based index into the sub-protocols array passed to *pszSubprotocols* in [WebSocketBeginClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginclienthandshake).

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns one of the following or a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

| Return code | Description |
| --- | --- |
| **E_INVALID_PROTOCOL_FORMAT** | Protocol data had an invalid format. |
| **E_UNSUPPORTED_SUBPROTOCOL** | Server does not accept any of the sub-protocols specified by the application. |
| **E_UNSUPPORTED_EXTENSION** | Server does not accept extensions specified by the application. |

## Remarks

This function must be called to complete the client-side handshake after a previous call to [WebSocketBeginClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginclienthandshake). Once the client-server handshake is complete, the application may use the session functions.

## See also

[WEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header)

[WebSocketBeginClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginclienthandshake)

[WebSocketBeginServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginserverhandshake)

[WebSocketEndServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendserverhandshake)