HRESULT WsCreateXmlSecurityToken(
  [in]           WS_XML_BUFFER                        *tokenXml,
  [in, optional] WS_SECURITY_KEY_HANDLE               *tokenKey,
                 const WS_XML_SECURITY_TOKEN_PROPERTY *properties,
  [in]           ULONG                                propertyCount,
                 WS_SECURITY_TOKEN                    **token,
  [in, optional] WS_ERROR                             *error
);