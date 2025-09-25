HRESULT WsCreateChannelForListener(
  [in]           WS_LISTENER               *listener,
                 const WS_CHANNEL_PROPERTY *properties,
  [in]           ULONG                     propertyCount,
                 WS_CHANNEL                **channel,
  [in, optional] WS_ERROR                  *error
);