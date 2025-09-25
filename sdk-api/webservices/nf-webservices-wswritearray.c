HRESULT WsWriteArray(
  [in]           WS_XML_WRITER       *writer,
  [in]           const WS_XML_STRING *localName,
  [in]           const WS_XML_STRING *ns,
  [in]           WS_VALUE_TYPE       valueType,
                 const void          *array,
  [in]           ULONG               arraySize,
  [in]           ULONG               itemOffset,
  [in]           ULONG               itemCount,
  [in, optional] WS_ERROR            *error
);