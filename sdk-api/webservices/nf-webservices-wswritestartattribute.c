HRESULT WsWriteStartAttribute(
  [in]           WS_XML_WRITER       *writer,
  [in, optional] const WS_XML_STRING *prefix,
  [in]           const WS_XML_STRING *localName,
  [in]           const WS_XML_STRING *ns,
  [in]           BOOL                singleQuote,
  [in, optional] WS_ERROR            *error
);