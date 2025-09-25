HRESULT WsGetSecurityContextProperty(
  [in]           WS_SECURITY_CONTEXT             *securityContext,
  [in]           WS_SECURITY_CONTEXT_PROPERTY_ID id,
                 void                            *value,
  [in]           ULONG                           valueSize,
  [in, optional] WS_ERROR                        *error
);