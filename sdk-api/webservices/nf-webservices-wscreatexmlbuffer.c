HRESULT WsCreateXmlBuffer(
  [in]           WS_HEAP                      *heap,
                 const WS_XML_BUFFER_PROPERTY *properties,
  [in]           ULONG                        propertyCount,
                 WS_XML_BUFFER                **buffer,
  [in, optional] WS_ERROR                     *error
);