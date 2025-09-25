HRESULT WsAddCustomHeader(
  [in]           WS_MESSAGE                   *message,
  [in]           const WS_ELEMENT_DESCRIPTION *headerDescription,
  [in]           WS_WRITE_OPTION              writeOption,
  [in, ref]      const void                   *value,
  [in]           ULONG                        valueSize,
  [in]           ULONG                        headerAttributes,
  [in, optional] WS_ERROR                     *error
);