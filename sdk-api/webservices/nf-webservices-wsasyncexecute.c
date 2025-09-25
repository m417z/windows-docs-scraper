HRESULT WsAsyncExecute(
  [in]           WS_ASYNC_STATE         *asyncState,
  [in, optional] WS_ASYNC_FUNCTION      operation,
  [in]           WS_CALLBACK_MODEL      callbackModel,
  [in]           void                   *callbackState,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR               *error
);