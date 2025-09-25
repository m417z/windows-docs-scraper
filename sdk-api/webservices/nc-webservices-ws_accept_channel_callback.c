WS_ACCEPT_CHANNEL_CALLBACK WsAcceptChannelCallback;

HRESULT WsAcceptChannelCallback(
  [in]           void *listenerInstance,
  [in]           void *channelInstance,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}