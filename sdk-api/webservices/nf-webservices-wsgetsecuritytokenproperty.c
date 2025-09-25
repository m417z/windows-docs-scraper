HRESULT WsGetSecurityTokenProperty(
  [in]           WS_SECURITY_TOKEN             *securityToken,
  [in]           WS_SECURITY_TOKEN_PROPERTY_ID id,
                 void                          *value,
  [in]           ULONG                         valueSize,
  [in, optional] WS_HEAP                       *heap,
  [in, optional] WS_ERROR                      *error
);