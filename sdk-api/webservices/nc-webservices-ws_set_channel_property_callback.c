WS_SET_CHANNEL_PROPERTY_CALLBACK WsSetChannelPropertyCallback;

HRESULT WsSetChannelPropertyCallback(
  [in]           void *channelInstance,
  [in]           WS_CHANNEL_PROPERTY_ID id,
                 const void *value,
  [in]           ULONG valueSize,
  [in, optional] WS_ERROR *error
)
{...}