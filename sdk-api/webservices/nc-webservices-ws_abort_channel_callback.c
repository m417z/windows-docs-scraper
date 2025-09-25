WS_ABORT_CHANNEL_CALLBACK WsAbortChannelCallback;

HRESULT WsAbortChannelCallback(
  [in]           void *channelInstance,
  [in, optional] WS_ERROR *error
)
{...}