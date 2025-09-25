HRESULT WsSetHeader(
  [in]           WS_MESSAGE      *message,
  [in]           WS_HEADER_TYPE  headerType,
  [in]           WS_TYPE         valueType,
  [in]           WS_WRITE_OPTION writeOption,
                 const void      *value,
  [in]           ULONG           valueSize,
  [in, optional] WS_ERROR        *error
);