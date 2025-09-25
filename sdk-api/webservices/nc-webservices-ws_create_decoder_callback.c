WS_CREATE_DECODER_CALLBACK WsCreateDecoderCallback;

HRESULT WsCreateDecoderCallback(
  [in]           void *createContext,
  [in]           WS_READ_CALLBACK readCallback,
  [in]           void *readContext,
                 void **decoderContext,
  [in, optional] WS_ERROR *error
)
{...}