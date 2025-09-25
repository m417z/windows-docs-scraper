HRESULT WsGetReaderProperty(
  [in]           WS_XML_READER             *reader,
  [in]           WS_XML_READER_PROPERTY_ID id,
                 void                      *value,
  [in]           ULONG                     valueSize,
  [in, optional] WS_ERROR                  *error
);