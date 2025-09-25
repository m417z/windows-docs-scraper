HRESULT WsGetCustomHeader(
  [in]           WS_MESSAGE                   *message,
  [in]           const WS_ELEMENT_DESCRIPTION *customHeaderDescription,
  [in]           WS_REPEATING_HEADER_OPTION   repeatingOption,
  [in]           ULONG                        headerIndex,
  [in]           WS_READ_OPTION               readOption,
  [in, optional] WS_HEAP                      *heap,
                 void                         *value,
  [in]           ULONG                        valueSize,
                 ULONG                        *headerAttributes,
  [in, optional] WS_ERROR                     *error
);