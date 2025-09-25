WS_DECODER_DECODE_CALLBACK WsDecoderDecodeCallback;

HRESULT WsDecoderDecodeCallback(
  [in]           void *encoderContext,
                 void *buffer,
  [in]           ULONG maxLength,
  [out]          ULONG *length,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}