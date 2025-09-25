WS_ASYNC_FUNCTION WsAsyncFunction;

HRESULT WsAsyncFunction(
  [in]           HRESULT hr,
  [in]           WS_CALLBACK_MODEL callbackModel,
  [in]           void *callbackState,
                 WS_ASYNC_OPERATION *next,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}