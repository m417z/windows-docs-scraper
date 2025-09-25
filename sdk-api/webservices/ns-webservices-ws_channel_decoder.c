typedef struct _WS_CHANNEL_DECODER {
  void                                 *createContext;
  WS_CREATE_DECODER_CALLBACK           createDecoderCallback;
  WS_DECODER_GET_CONTENT_TYPE_CALLBACK decoderGetContentTypeCallback;
  WS_DECODER_START_CALLBACK            decoderStartCallback;
  WS_DECODER_DECODE_CALLBACK           decoderDecodeCallback;
  WS_DECODER_END_CALLBACK              decoderEndCallback;
  WS_FREE_DECODER_CALLBACK             freeDecoderCallback;
} WS_CHANNEL_DECODER;