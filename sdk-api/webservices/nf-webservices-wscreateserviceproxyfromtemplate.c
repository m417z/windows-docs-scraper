HRESULT WsCreateServiceProxyFromTemplate(
  [in]           WS_CHANNEL_TYPE          channelType,
                 const WS_PROXY_PROPERTY  *properties,
  [in]           const ULONG              propertyCount,
  [in]           WS_BINDING_TEMPLATE_TYPE templateType,
                 void                     *templateValue,
  [in]           ULONG                    templateSize,
  [in]           const void               *templateDescription,
  [in]           ULONG                    templateDescriptionSize,
                 WS_SERVICE_PROXY         **serviceProxy,
  [in, optional] WS_ERROR                 *error
);