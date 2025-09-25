WS_OPEN_LISTENER_CALLBACK WsOpenListenerCallback;

HRESULT WsOpenListenerCallback(
  [in]           void *listenerInstance,
  [in]           const WS_STRING *url,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}