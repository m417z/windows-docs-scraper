WS_CLOSE_LISTENER_CALLBACK WsCloseListenerCallback;

HRESULT WsCloseListenerCallback(
  [in]           void *listenerInstance,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}