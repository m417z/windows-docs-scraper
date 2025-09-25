WS_SERVICE_CLOSE_CHANNEL_CALLBACK WsServiceCloseChannelCallback;

HRESULT WsServiceCloseChannelCallback(
  [in]           const WS_OPERATION_CONTEXT *context,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext
)
{...}