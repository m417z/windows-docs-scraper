WS_CREATE_ENCODER_CALLBACK WsCreateEncoderCallback;

HRESULT WsCreateEncoderCallback(
  [in]           void *createContext,
  [in]           WS_WRITE_CALLBACK writeCallback,
  [in]           void *writeContext,
                 void **encoderContext,
  [in, optional] WS_ERROR *error
)
{...}