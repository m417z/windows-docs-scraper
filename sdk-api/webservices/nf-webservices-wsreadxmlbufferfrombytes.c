HRESULT WsReadXmlBufferFromBytes(
  [in]           WS_XML_READER                *reader,
  [in, optional] const WS_XML_READER_ENCODING *encoding,
                 const WS_XML_READER_PROPERTY *properties,
  [in]           ULONG                        propertyCount,
                 const void                   *bytes,
  [in]           ULONG                        byteCount,
  [in]           WS_HEAP                      *heap,
                 WS_XML_BUFFER                **xmlBuffer,
  [in, optional] WS_ERROR                     *error
);