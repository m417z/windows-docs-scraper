HRESULT WsAddMappedHeader(
  [in]           WS_MESSAGE          *message,
  [in]           const WS_XML_STRING *headerName,
  [in]           WS_TYPE             valueType,
  [in]           WS_WRITE_OPTION     writeOption,
  [in]           const void          *value,
  [in]           ULONG               valueSize,
  [in, optional] WS_ERROR            *error
);