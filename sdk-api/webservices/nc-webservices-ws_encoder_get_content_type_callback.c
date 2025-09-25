WS_ENCODER_GET_CONTENT_TYPE_CALLBACK WsEncoderGetContentTypeCallback;

HRESULT WsEncoderGetContentTypeCallback(
  [in]           void *encoderContext,
  [in]           const WS_STRING *contentType,
  [out]          WS_STRING *newContentType,
  [out]          WS_STRING *contentEncoding,
  [in, optional] WS_ERROR *error
)
{...}