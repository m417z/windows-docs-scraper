HRESULT WsWriteXmlBufferToBytes(
  [in]           WS_XML_WRITER                *writer,
  [in]           WS_XML_BUFFER                *xmlBuffer,
  [in, optional] const WS_XML_WRITER_ENCODING *encoding,
                 const WS_XML_WRITER_PROPERTY *properties,
  [in]           ULONG                        propertyCount,
  [in]           WS_HEAP                      *heap,
                 void                         **bytes,
  [out]          ULONG                        *byteCount,
  [in, optional] WS_ERROR                     *error
);