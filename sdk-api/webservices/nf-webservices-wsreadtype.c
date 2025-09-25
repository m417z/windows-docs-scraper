HRESULT WsReadType(
  [in]           WS_XML_READER   *reader,
  [in]           WS_TYPE_MAPPING typeMapping,
  [in]           WS_TYPE         type,
  [in, optional] const void      *typeDescription,
  [in]           WS_READ_OPTION  readOption,
  [in, optional] WS_HEAP         *heap,
                 void            *value,
  [in]           ULONG           valueSize,
  [in, optional] WS_ERROR        *error
);