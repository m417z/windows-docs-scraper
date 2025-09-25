HRESULT WsSetOutput(
  [in]           WS_XML_WRITER                *writer,
  [in, optional] const WS_XML_WRITER_ENCODING *encoding,
  [in, optional] const WS_XML_WRITER_OUTPUT   *output,
                 const WS_XML_WRITER_PROPERTY *properties,
  [in]           ULONG                        propertyCount,
  [in, optional] WS_ERROR                     *error
);