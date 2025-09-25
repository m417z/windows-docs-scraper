WS_ASYNC_CALLBACK WsAsyncCallback;

void WsAsyncCallback(
  [in] HRESULT errorCode,
  [in] WS_CALLBACK_MODEL callbackModel,
  [in] void *callbackState
)
{...}