HRESULT WsCreateListener(
  [in]           WS_CHANNEL_TYPE               channelType,
  [in]           WS_CHANNEL_BINDING            channelBinding,
                 const WS_LISTENER_PROPERTY    *properties,
  [in]           ULONG                         propertyCount,
  [in, optional] const WS_SECURITY_DESCRIPTION *securityDescription,
                 WS_LISTENER                   **listener,
  [in, optional] WS_ERROR                      *error
);