HRESULT WsGetNamespaceFromPrefix(
  [in]           WS_XML_READER       *reader,
  [in]           const WS_XML_STRING *prefix,
  [in]           BOOL                required,
                 const WS_XML_STRING **ns,
  [in, optional] WS_ERROR            *error
);