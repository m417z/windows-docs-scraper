HRESULT WsWriteQualifiedName(
  [in]           WS_XML_WRITER       *writer,
  [in, optional] const WS_XML_STRING *prefix,
  [in]           const WS_XML_STRING *localName,
  [in, optional] const WS_XML_STRING *ns,
  [in, optional] WS_ERROR            *error
);