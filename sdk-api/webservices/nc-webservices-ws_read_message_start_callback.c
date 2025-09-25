WS_READ_MESSAGE_START_CALLBACK WsReadMessageStartCallback;

HRESULT WsReadMessageStartCallback(
  [in]           void *channelInstance,
  [in]           WS_MESSAGE *message,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}