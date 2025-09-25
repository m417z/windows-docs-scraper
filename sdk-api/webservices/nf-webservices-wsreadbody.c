HRESULT WsReadBody(
  [in]           WS_MESSAGE                   *message,
  [in]           const WS_ELEMENT_DESCRIPTION *bodyDescription,
  [in]           WS_READ_OPTION               readOption,
  [in, optional] WS_HEAP                      *heap,
                 void                         *value,
  [in]           ULONG                        valueSize,
  [in, optional] WS_ERROR                     *error
);