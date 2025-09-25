WS_SERVICE_MESSAGE_RECEIVE_CALLBACK WsServiceMessageReceiveCallback;

HRESULT WsServiceMessageReceiveCallback(
  [in]           const WS_OPERATION_CONTEXT *context,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}