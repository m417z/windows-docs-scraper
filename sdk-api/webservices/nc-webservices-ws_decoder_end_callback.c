WS_DECODER_END_CALLBACK WsDecoderEndCallback;

HRESULT WsDecoderEndCallback(
  [in]           void *encoderContext,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}