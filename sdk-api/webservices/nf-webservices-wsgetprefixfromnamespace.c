HRESULT WsGetPrefixFromNamespace(
  [in]           WS_XML_WRITER       *writer,
  [in]           const WS_XML_STRING *ns,
  [in]           BOOL                required,
                 const WS_XML_STRING **prefix,
  [in, optional] WS_ERROR            *error
);