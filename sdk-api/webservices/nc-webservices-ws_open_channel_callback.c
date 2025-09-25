WS_OPEN_CHANNEL_CALLBACK WsOpenChannelCallback;

HRESULT WsOpenChannelCallback(
  [in]           void *channelInstance,
  [in]           const WS_ENDPOINT_ADDRESS *endpointAddress,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}