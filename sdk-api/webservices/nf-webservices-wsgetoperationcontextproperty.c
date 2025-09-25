HRESULT WsGetOperationContextProperty(
  [in]           const WS_OPERATION_CONTEXT             *context,
  [in]           const WS_OPERATION_CONTEXT_PROPERTY_ID id,
                 void                                   *value,
  [in]           ULONG                                  valueSize,
  [in, optional] WS_ERROR                               *error
);