WS_PUSH_BYTES_CALLBACK WsPushBytesCallback;

HRESULT WsPushBytesCallback(
  [in]           void *callbackState,
  [in]           WS_WRITE_CALLBACK writeCallback,
  [in]           void *writeCallbackState,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}