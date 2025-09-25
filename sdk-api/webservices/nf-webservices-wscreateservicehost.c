HRESULT WsCreateServiceHost(
                 const WS_SERVICE_ENDPOINT **endpoints,
  [in]           const USHORT              endpointCount,
                 const WS_SERVICE_PROPERTY *serviceProperties,
  [in]           ULONG                     servicePropertyCount,
                 WS_SERVICE_HOST           **serviceHost,
  [in, optional] WS_ERROR                  *error
);