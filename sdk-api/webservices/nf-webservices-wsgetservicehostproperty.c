HRESULT WsGetServiceHostProperty(
  [in]           WS_SERVICE_HOST              *serviceHost,
  [in]           const WS_SERVICE_PROPERTY_ID id,
                 void                         *value,
  [in]           ULONG                        valueSize,
  [in, optional] WS_ERROR                     *error
);