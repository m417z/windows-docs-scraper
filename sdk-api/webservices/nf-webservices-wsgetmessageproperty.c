HRESULT WsGetMessageProperty(
  [in]           WS_MESSAGE             *message,
  [in]           WS_MESSAGE_PROPERTY_ID id,
                 void                   *value,
  [in]           ULONG                  valueSize,
  [in, optional] WS_ERROR               *error
);