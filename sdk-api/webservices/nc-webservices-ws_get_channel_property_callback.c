WS_GET_CHANNEL_PROPERTY_CALLBACK WsGetChannelPropertyCallback;

HRESULT WsGetChannelPropertyCallback(
  [in]           void *channelInstance,
  [in]           WS_CHANNEL_PROPERTY_ID id,
                 void *value,
  [in]           ULONG valueSize,
  [in, optional] WS_ERROR *error
)
{...}