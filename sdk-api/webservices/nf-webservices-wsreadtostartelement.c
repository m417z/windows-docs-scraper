HRESULT WsReadToStartElement(
  [in]           WS_XML_READER       *reader,
  [in, optional] const WS_XML_STRING *localName,
  [in, optional] const WS_XML_STRING *ns,
                 BOOL                *found,
  [in, optional] WS_ERROR            *error
);