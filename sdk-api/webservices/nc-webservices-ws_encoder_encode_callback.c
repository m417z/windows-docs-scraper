WS_ENCODER_ENCODE_CALLBACK WsEncoderEncodeCallback;

HRESULT WsEncoderEncodeCallback(
  [in]           void *encoderContext,
                 const WS_BYTES *buffers,
  [in]           ULONG count,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}