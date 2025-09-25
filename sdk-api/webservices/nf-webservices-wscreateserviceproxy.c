HRESULT WsCreateServiceProxy(
  [in]           const WS_CHANNEL_TYPE         channelType,
  [in]           const WS_CHANNEL_BINDING      channelBinding,
  [in, optional] const WS_SECURITY_DESCRIPTION *securityDescription,
                 const WS_PROXY_PROPERTY       *properties,
  [in]           const ULONG                   propertyCount,
                 const WS_CHANNEL_PROPERTY     *channelProperties,
  [in]           const ULONG                   channelPropertyCount,
                 WS_SERVICE_PROXY              **serviceProxy,
  [in, optional] WS_ERROR                      *error
);