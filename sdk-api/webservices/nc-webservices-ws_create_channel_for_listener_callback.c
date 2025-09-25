WS_CREATE_CHANNEL_FOR_LISTENER_CALLBACK WsCreateChannelForListenerCallback;

HRESULT WsCreateChannelForListenerCallback(
  [in]           void *listenerInstance,
                 const void *channelParameters,
  [in]           ULONG channelParametersSize,
                 void **channelInstance,
  [in, optional] WS_ERROR *error
)
{...}