HRESULT WsSendMessage(
  [in]           WS_CHANNEL                   *channel,
  [in]           WS_MESSAGE                   *message,
  [in]           const WS_MESSAGE_DESCRIPTION *messageDescription,
  [in]           WS_WRITE_OPTION              writeOption,
                 const void                   *bodyValue,
  [in]           ULONG                        bodyValueSize,
  [in, optional] const WS_ASYNC_CONTEXT       *asyncContext,
  [in, optional] WS_ERROR                     *error
);