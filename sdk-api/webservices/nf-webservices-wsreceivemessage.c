HRESULT WsReceiveMessage(
  [in]           WS_CHANNEL                   *channel,
  [in]           WS_MESSAGE                   *message,
                 const WS_MESSAGE_DESCRIPTION **messageDescriptions,
  [in]           ULONG                        messageDescriptionCount,
  [in]           WS_RECEIVE_OPTION            receiveOption,
  [in]           WS_READ_OPTION               readBodyOption,
  [in, optional] WS_HEAP                      *heap,
                 void                         *value,
  [in]           ULONG                        valueSize,
                 ULONG                        *index,
  [in, optional] const WS_ASYNC_CONTEXT       *asyncContext,
  [in, optional] WS_ERROR                     *error
);