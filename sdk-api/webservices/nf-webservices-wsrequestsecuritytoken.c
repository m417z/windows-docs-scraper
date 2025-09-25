HRESULT WsRequestSecurityToken(
  [in]           WS_CHANNEL                               *channel,
                 const WS_REQUEST_SECURITY_TOKEN_PROPERTY *properties,
  [in]           ULONG                                    propertyCount,
                 WS_SECURITY_TOKEN                        **token,
  [in, optional] const WS_ASYNC_CONTEXT                   *asyncContext,
  [in, optional] WS_ERROR                                 *error
);