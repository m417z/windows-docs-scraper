HRESULT WsGetMappedHeader(
  [in]           WS_MESSAGE                 *message,
  [in]           const WS_XML_STRING        *headerName,
  [in]           WS_REPEATING_HEADER_OPTION repeatingOption,
  [in]           ULONG                      headerIndex,
  [in]           WS_TYPE                    valueType,
  [in]           WS_READ_OPTION             readOption,
  [in, optional] WS_HEAP                    *heap,
                 void                       *value,
  [in]           ULONG                      valueSize,
  [in, optional] WS_ERROR                   *error
);