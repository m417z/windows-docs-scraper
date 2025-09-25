WS_PULL_BYTES_CALLBACK WsPullBytesCallback;

HRESULT WsPullBytesCallback(
  [in]           void *callbackState,
                 void *bytes,
  [in]           ULONG maxSize,
  [out]          ULONG *actualSize,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}