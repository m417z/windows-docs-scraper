HRESULT WsSetInput(
  [in]           WS_XML_READER                *reader,
  [in, optional] const WS_XML_READER_ENCODING *encoding,
  [in, optional] const WS_XML_READER_INPUT    *input,
                 const WS_XML_READER_PROPERTY *properties,
  [in]           ULONG                        propertyCount,
  [in, optional] WS_ERROR                     *error
);