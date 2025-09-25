HRESULT WebSocketBeginServerHandshake(
  [in]           WEB_SOCKET_HANDLE             hWebSocket,
  [in, optional] PCSTR                         pszSubprotocolSelected,
  [in, optional] PCSTR                         *pszExtensionSelected,
  [in]           ULONG                         ulExtensionSelectedCount,
  [in]           const PWEB_SOCKET_HTTP_HEADER pRequestHeaders,
  [in]           ULONG                         ulRequestHeaderCount,
  [out]          PWEB_SOCKET_HTTP_HEADER       *pResponseHeaders,
  [out]          ULONG                         *pulResponseHeaderCount
);