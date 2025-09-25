HRESULT WebSocketEndClientHandshake(
  [in]                WEB_SOCKET_HANDLE             hWebSocket,
  [in]                const PWEB_SOCKET_HTTP_HEADER pResponseHeaders,
  [in]                ULONG                         ulReponseHeaderCount,
  [in, out, optional] ULONG                         *pulSelectedExtensions,
  [in, out, optional] ULONG                         *pulSelectedExtensionCount,
  [in, out, optional] ULONG                         *pulSelectedSubprotocol
);