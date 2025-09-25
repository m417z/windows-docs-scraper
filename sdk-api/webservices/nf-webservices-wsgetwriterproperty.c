HRESULT WsGetWriterProperty(
  [in]           WS_XML_WRITER             *writer,
  [in]           WS_XML_WRITER_PROPERTY_ID id,
                 void                      *value,
  [in]           ULONG                     valueSize,
  [in, optional] WS_ERROR                  *error
);