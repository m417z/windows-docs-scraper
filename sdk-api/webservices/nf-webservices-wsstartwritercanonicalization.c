HRESULT WsStartWriterCanonicalization(
  [in]           WS_XML_WRITER                          *writer,
  [in]           WS_WRITE_CALLBACK                      writeCallback,
  [in]           void                                   *writeCallbackState,
                 const WS_XML_CANONICALIZATION_PROPERTY *properties,
  [in]           ULONG                                  propertyCount,
  [in, optional] WS_ERROR                               *error
);