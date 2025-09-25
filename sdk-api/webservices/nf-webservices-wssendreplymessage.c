HRESULT WsSendReplyMessage(
  [in]           WS_CHANNEL                   *channel,
  [in]           WS_MESSAGE                   *replyMessage,
  [in]           const WS_MESSAGE_DESCRIPTION *replyMessageDescription,
  [in]           WS_WRITE_OPTION              writeOption,
                 const void                   *replyBodyValue,
  [in]           ULONG                        replyBodyValueSize,
  [in]           WS_MESSAGE                   *requestMessage,
  [in, optional] const WS_ASYNC_CONTEXT       *asyncContext,
  [in, optional] WS_ERROR                     *error
);