WS_DECODER_START_CALLBACK WsDecoderStartCallback;

HRESULT WsDecoderStartCallback(
  [in]           void *encoderContext,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}