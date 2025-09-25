WS_SERVICE_STUB_CALLBACK WsServiceStubCallback;

HRESULT WsServiceStubCallback(
  [in]           const WS_OPERATION_CONTEXT *context,
  [in]           void *frame,
  [in]           const void *callback,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}