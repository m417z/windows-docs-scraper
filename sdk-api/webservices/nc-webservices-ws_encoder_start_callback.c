WS_ENCODER_START_CALLBACK WsEncoderStartCallback;

HRESULT WsEncoderStartCallback(
  [in]           void *encoderContext,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}