# WebSocketBeginServerHandshake function

## Description

The **WebSocketBeginServerHandshake** function begins the server-side handshake.

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

 WebSocket session handle returned by a previous call to [WebSocketCreateServerHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateserverhandle).

### `pszSubprotocolSelected` [in, optional]

Type: **PCSTR**

A pointer to a sub-protocol value chosen by the application. Must contain one subprotocol.

### `pszExtensionSelected` [in, optional]

Type: **PCSTR***

A pointer to a list of extensions chosen by the application. Must contain one extension per entry.

### `ulExtensionSelectedCount` [in]

Type: **ULONG**

Number of extensions in *pszExtensionSelected*.

### `pRequestHeaders` [in]

Type: **const [PWEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header)**

Pointer to an array of [WEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header) structures that contain the request headers received by the application.

### `ulRequestHeaderCount` [in]

Type: **ULONG**

Number of request headers in *pRequestHeaders*.

### `pResponseHeaders` [out]

Type: **[PWEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header)***

On successful output, a pointer to an array or [WEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header) structures that contain the response headers to be sent by the application.

### `pulResponseHeaderCount` [out]

Type: **ULONG***

On successful output, number of response headers in *pResponseHeaders*.

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns one of the following or a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

| Return code | Description |
| --- | --- |
| **E_INVALID_PROTOCOL_FORMAT** | Protocol data had an invalid format. |

## Remarks

To complete the server-side handshake, applications must call [WebSocketEndServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendserverhandshake) or any of the session functions. Once the client-server handshake is complete, the application may use the session functions.

## See also

[WEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header)

[WebSocketBeginClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginclienthandshake)

[WebSocketEndClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendclienthandshake)

[WebSocketEndServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendserverhandshake)