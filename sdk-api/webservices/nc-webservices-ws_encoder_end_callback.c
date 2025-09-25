WS_ENCODER_END_CALLBACK WsEncoderEndCallback;

HRESULT WsEncoderEndCallback(
  [in]           void *encoderContext,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}