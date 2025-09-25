HRESULT WsCreateChannel(
  [in]           WS_CHANNEL_TYPE               channelType,
  [in]           WS_CHANNEL_BINDING            channelBinding,
  [in]           const WS_CHANNEL_PROPERTY     *properties,
  [in]           ULONG                         propertyCount,
  [in, optional] const WS_SECURITY_DESCRIPTION *securityDescription,
                 WS_CHANNEL                    **channel,
  [in, optional] WS_ERROR                      *error
);