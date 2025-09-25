WS_ABORT_LISTENER_CALLBACK WsAbortListenerCallback;

HRESULT WsAbortListenerCallback(
  [in]           void *listenerInstance,
  [in, optional] WS_ERROR *error
)
{...}