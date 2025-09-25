HRESULT WsGetServiceProxyProperty(
  [in]           WS_SERVICE_PROXY           *serviceProxy,
  [in]           const WS_PROXY_PROPERTY_ID id,
                 void                       *value,
  [in]           ULONG                      valueSize,
  [in, optional] WS_ERROR                   *error
);