WS_CREATE_LISTENER_CALLBACK WsCreateListenerCallback;

HRESULT WsCreateListenerCallback(
  [in]           WS_CHANNEL_TYPE channelType,
                 const void *listenerParameters,
  [in]           ULONG listenerParametersSize,
                 void **listenerInstance,
  [in, optional] WS_ERROR *error
)
{...}