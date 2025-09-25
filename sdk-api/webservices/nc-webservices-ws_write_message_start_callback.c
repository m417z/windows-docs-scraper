WS_WRITE_MESSAGE_START_CALLBACK WsWriteMessageStartCallback;

HRESULT WsWriteMessageStartCallback(
  [in]           void *channelInstance,
  [in]           WS_MESSAGE *message,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}