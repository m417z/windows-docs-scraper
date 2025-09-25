HRESULT WsCreateMessageForChannel(
  [in]           WS_CHANNEL                *channel,
                 const WS_MESSAGE_PROPERTY *properties,
  [in]           ULONG                     propertyCount,
                 WS_MESSAGE                **message,
  [in, optional] WS_ERROR                  *error
);