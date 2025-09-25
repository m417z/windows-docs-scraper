WS_SHUTDOWN_SESSION_CHANNEL_CALLBACK WsShutdownSessionChannelCallback;

HRESULT WsShutdownSessionChannelCallback(
  [in]           void *channelInstance,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}