WS_CREATE_CHANNEL_CALLBACK WsCreateChannelCallback;

HRESULT WsCreateChannelCallback(
  [in]           WS_CHANNEL_TYPE channelType,
                 const void *channelParameters,
  [in]           ULONG channelParametersSize,
                 void **channelInstance,
  [in, optional] WS_ERROR *error
)
{...}