WS_DECODER_GET_CONTENT_TYPE_CALLBACK WsDecoderGetContentTypeCallback;

HRESULT WsDecoderGetContentTypeCallback(
  [in]           void *decoderContext,
  [in]           const WS_STRING *contentType,
  [in, optional] const WS_STRING *contentEncoding,
  [out]          WS_STRING *newContentType,
  [in, optional] WS_ERROR *error
)
{...}