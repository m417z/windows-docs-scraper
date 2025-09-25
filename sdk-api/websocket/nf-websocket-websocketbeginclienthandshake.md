# WebSocketBeginClientHandshake function

## Description

The **WebSocketBeginClientHandshake** function begins the client-side handshake.

## Parameters

### `hWebSocket` [in]

Type: **[WEB_SOCKET_HANDLE](https://learn.microsoft.com/windows/desktop/WebSock/web-socket-protocol-component-api-data-types)**

 WebSocket session handle returned by a previous call to [WebSocketCreateClientHandle](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketcreateclienthandle).

### `pszSubprotocols` [in, optional]

Type: **PCSTR***

Pointer to an array of sub-protocols chosen by the application. Once the client-server handshake is complete, the application must use the sub-protocol returned by [WebSocketEndClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendclienthandshake). Must contain one subprotocol per entry.

### `ulSubprotocolCount` [in]

Type: **ULONG**

Number of sub-protocols in *pszSubprotocols*.

### `pszExtensions` [in, optional]

Type: **PCSTR***

Pointer to an array of extensions chosen by the application. Once the client-server handshake is complete, the application must use the extension returned by [WebSocketEndClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendclienthandshake). Must contain one extension per entry.

### `ulExtensionCount` [in]

Type: **ULONG**

Number of extensions in *pszExtensions*.

### `pInitialHeaders` [in, optional]

Type: **const [PWEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header)**

Pointer to an array of [WEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header) structures that contain the request headers to be sent by the application. The array must include the *Host HTTP* header as defined in [RFC 2616](http://tools.ietf.org/html/rfc2616).

### `ulInitialHeaderCount` [in]

Type: **ULONG**

Number of request headers in *pInitialHeaders*.

### `pAdditionalHeaders` [out]

Type: **[PWEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header)**

On successful output, pointer to an array of [WEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header) structures that contain the request headers to be sent by the application. If any of these headers were specified in *pInitialHeaders*, the header must be replaced.

### `pulAdditionalHeaderCount` [out]

Type: **ULONG***

On successful output, number of response headers in *pAdditionalHeaders*.

## Return value

Type: **HRESULT**

If the function succeeds, it returns **S_OK**.

If the function fails, it returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in WinError.h.

## Remarks

To complete the client-side handshake, applications must call [WebSocketEndClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendclienthandshake). Once the client-server handshake is complete, the application may use the session functions.

## See also

[WEB_SOCKET_HTTP_HEADER](https://learn.microsoft.com/windows/desktop/api/websocket/ns-websocket-web_socket_http_header)

[WebSocketBeginServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketbeginserverhandshake)

[WebSocketEndClientHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendclienthandshake)

[WebSocketEndServerHandshake](https://learn.microsoft.com/windows/desktop/api/websocket/nf-websocket-websocketendserverhandshake)