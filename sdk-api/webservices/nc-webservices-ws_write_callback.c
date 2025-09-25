WS_WRITE_CALLBACK WsWriteCallback;

HRESULT WsWriteCallback(
  [in]           void *callbackState,
                 const WS_BYTES *buffers,
  [in]           ULONG count,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}