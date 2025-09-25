HRESULT WsReadQualifiedName(
  [in]           WS_XML_READER *reader,
  [in]           WS_HEAP       *heap,
                 WS_XML_STRING *prefix,
  [out]          WS_XML_STRING *localName,
                 WS_XML_STRING *ns,
  [in, optional] WS_ERROR      *error
);