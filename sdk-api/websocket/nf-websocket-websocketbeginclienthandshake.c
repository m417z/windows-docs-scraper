HRESULT WebSocketBeginClientHandshake(
  [in]           WEB_SOCKET_HANDLE             hWebSocket,
  [in, optional] PCSTR                         *pszSubprotocols,
  [in]           ULONG                         ulSubprotocolCount,
  [in, optional] PCSTR                         *pszExtensions,
  [in]           ULONG                         ulExtensionCount,
  [in, optional] const PWEB_SOCKET_HTTP_HEADER pInitialHeaders,
  [in]           ULONG                         ulInitialHeaderCount,
  [out]          PWEB_SOCKET_HTTP_HEADER       *pAdditionalHeaders,
  [out]          ULONG                         *pulAdditionalHeaderCount
);