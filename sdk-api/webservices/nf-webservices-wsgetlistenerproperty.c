HRESULT WsGetListenerProperty(
  [in]           WS_LISTENER             *listener,
  [in]           WS_LISTENER_PROPERTY_ID id,
                 void                    *value,
  [in]           ULONG                   valueSize,
  [in, optional] WS_ERROR                *error
);