HRESULT WsGetHeader(
  [in]           WS_MESSAGE     *message,
  [in]           WS_HEADER_TYPE headerType,
  [in]           WS_TYPE        valueType,
  [in]           WS_READ_OPTION readOption,
  [in, optional] WS_HEAP        *heap,
                 void           *value,
  [in]           ULONG          valueSize,
  [in, optional] WS_ERROR       *error
);