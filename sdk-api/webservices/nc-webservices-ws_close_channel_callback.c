WS_CLOSE_CHANNEL_CALLBACK WsCloseChannelCallback;

HRESULT WsCloseChannelCallback(
  [in]           void *channelInstance,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}