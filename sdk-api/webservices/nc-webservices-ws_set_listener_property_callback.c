WS_SET_LISTENER_PROPERTY_CALLBACK WsSetListenerPropertyCallback;

HRESULT WsSetListenerPropertyCallback(
  [in]           void *listenerInstance,
  [in]           WS_LISTENER_PROPERTY_ID id,
                 const void *value,
  [in]           ULONG valueSize,
  [in, optional] WS_ERROR *error
)
{...}