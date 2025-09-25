WS_GET_LISTENER_PROPERTY_CALLBACK WsGetListenerPropertyCallback;

HRESULT WsGetListenerPropertyCallback(
  [in]           void *listenerInstance,
  [in]           WS_LISTENER_PROPERTY_ID id,
                 void *value,
  [in]           ULONG valueSize,
  [in, optional] WS_ERROR *error
)
{...}