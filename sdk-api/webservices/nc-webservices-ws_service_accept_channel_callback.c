WS_SERVICE_ACCEPT_CHANNEL_CALLBACK WsServiceAcceptChannelCallback;

HRESULT WsServiceAcceptChannelCallback(
  [in]           const WS_OPERATION_CONTEXT *context,
                 void **channelState,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}