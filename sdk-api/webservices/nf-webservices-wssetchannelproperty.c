HRESULT WsSetChannelProperty(
  [in]           WS_CHANNEL             *channel,
  [in]           WS_CHANNEL_PROPERTY_ID id,
                 const void             *value,
  [in]           ULONG                  valueSize,
  [in, optional] WS_ERROR               *error
);