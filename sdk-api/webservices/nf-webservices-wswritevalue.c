HRESULT WsWriteValue(
  [in]           WS_XML_WRITER *writer,
  [in]           WS_VALUE_TYPE valueType,
                 const void    *value,
  [in]           ULONG         valueSize,
  [in, optional] WS_ERROR      *error
);