HRESULT WsCreateServiceEndpointFromTemplate(
  [in]           WS_CHANNEL_TYPE                    channelType,
  [in]           const WS_SERVICE_ENDPOINT_PROPERTY *properties,
  [in]           ULONG                              propertyCount,
  [in, optional] const WS_STRING                    *addressUrl,
  [in]           const WS_SERVICE_CONTRACT          *contract,
  [in]           WS_SERVICE_SECURITY_CALLBACK       authorizationCallback,
  [in]           WS_HEAP                            *heap,
  [in]           WS_BINDING_TEMPLATE_TYPE           templateType,
  [in]           void                               *templateValue,
  [in]           ULONG                              templateSize,
  [in]           const void                         *templateDescription,
  [in]           ULONG                              templateDescriptionSize,
  [out]          WS_SERVICE_ENDPOINT                **serviceEndpoint,
  [in, optional] WS_ERROR                           *error
);