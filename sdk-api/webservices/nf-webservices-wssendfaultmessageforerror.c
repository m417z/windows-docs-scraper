HRESULT WsSendFaultMessageForError(
  [in]           WS_CHANNEL             *channel,
  [in]           WS_MESSAGE             *replyMessage,
  [in]           WS_ERROR               *faultError,
  [in]           HRESULT                faultErrorCode,
  [in]           WS_FAULT_DISCLOSURE    faultDisclosure,
  [in]           WS_MESSAGE             *requestMessage,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR               *error
);