WS_ABANDON_MESSAGE_CALLBACK WsAbandonMessageCallback;

HRESULT WsAbandonMessageCallback(
  [in]           void *channelInstance,
  [in]           WS_MESSAGE *message,
  [in, optional] WS_ERROR *error
)
{...}