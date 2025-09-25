HRESULT WsDecodeUrl(
  [in]           const WS_STRING *url,
  [in]           ULONG           flags,
  [in]           WS_HEAP         *heap,
                 WS_URL          **outUrl,
  [in, optional] WS_ERROR        *error
);