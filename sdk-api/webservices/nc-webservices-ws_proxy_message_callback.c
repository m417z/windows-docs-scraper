WS_PROXY_MESSAGE_CALLBACK WsProxyMessageCallback;

HRESULT WsProxyMessageCallback(
  [in]           WS_MESSAGE *message,
  [in]           WS_HEAP *heap,
  [in]           void *state,
  [in, optional] WS_ERROR *error
)
{...}