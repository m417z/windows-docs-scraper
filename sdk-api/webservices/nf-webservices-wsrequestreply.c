HRESULT WsRequestReply(
  [in]           WS_CHANNEL                   *channel,
  [in]           WS_MESSAGE                   *requestMessage,
  [in]           const WS_MESSAGE_DESCRIPTION *requestMessageDescription,
  [in]           WS_WRITE_OPTION              writeOption,
                 const void                   *requestBodyValue,
  [in]           ULONG                        requestBodyValueSize,
  [in]           WS_MESSAGE                   *replyMessage,
  [in]           const WS_MESSAGE_DESCRIPTION *replyMessageDescription,
  [in]           WS_READ_OPTION               readOption,
  [in, optional] WS_HEAP                      *heap,
                 void                         *value,
  [in]           ULONG                        valueSize,
  [in, optional] const WS_ASYNC_CONTEXT       *asyncContext,
  [in, optional] WS_ERROR                     *error
);