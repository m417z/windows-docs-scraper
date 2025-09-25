HRESULT WsWriteAttribute(
  [in]           WS_XML_WRITER                  *writer,
  [in]           const WS_ATTRIBUTE_DESCRIPTION *attributeDescription,
  [in]           WS_WRITE_OPTION                writeOption,
                 const void                     *value,
  [in]           ULONG                          valueSize,
  [in, optional] WS_ERROR                       *error
);