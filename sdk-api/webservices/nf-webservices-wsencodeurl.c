HRESULT WsEncodeUrl(
  [in]           const WS_URL *url,
  [in]           ULONG        flags,
  [in]           WS_HEAP      *heap,
  [out]          WS_STRING    *outUrl,
  [in, optional] WS_ERROR     *error
);