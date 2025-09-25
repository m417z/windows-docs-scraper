HRESULT WsWriteBody(
  [in]           WS_MESSAGE                   *message,
  [in]           const WS_ELEMENT_DESCRIPTION *bodyDescription,
  [in]           WS_WRITE_OPTION              writeOption,
                 const void                   *value,
  [in]           ULONG                        valueSize,
  [in, optional] WS_ERROR                     *error
);