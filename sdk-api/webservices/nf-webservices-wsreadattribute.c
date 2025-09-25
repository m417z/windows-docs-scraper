HRESULT WsReadAttribute(
  [in]           WS_XML_READER                  *reader,
  [in]           const WS_ATTRIBUTE_DESCRIPTION *attributeDescription,
  [in]           WS_READ_OPTION                 readOption,
  [in, optional] WS_HEAP                        *heap,
                 void                           *value,
  [in]           ULONG                          valueSize,
  [in, optional] WS_ERROR                       *error
);