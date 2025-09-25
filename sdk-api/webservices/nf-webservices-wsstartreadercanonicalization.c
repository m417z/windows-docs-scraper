HRESULT WsStartReaderCanonicalization(
  [in]           WS_XML_READER                          *reader,
  [in]           WS_WRITE_CALLBACK                      writeCallback,
  [in]           void                                   *writeCallbackState,
                 const WS_XML_CANONICALIZATION_PROPERTY *properties,
  [in]           ULONG                                  propertyCount,
  [in, optional] WS_ERROR                               *error
);