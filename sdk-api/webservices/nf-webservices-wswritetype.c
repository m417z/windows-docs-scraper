HRESULT WsWriteType(
  [in]           WS_XML_WRITER   *writer,
  [in]           WS_TYPE_MAPPING typeMapping,
  [in]           WS_TYPE         type,
  [in, optional] const void      *typeDescription,
  [in]           WS_WRITE_OPTION writeOption,
                 const void      *value,
  [in]           ULONG           valueSize,
  [in, optional] WS_ERROR        *error
);