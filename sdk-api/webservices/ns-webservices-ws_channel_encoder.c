typedef struct _WS_CHANNEL_ENCODER {
  void                                 *createContext;
  WS_CREATE_ENCODER_CALLBACK           createEncoderCallback;
  WS_ENCODER_GET_CONTENT_TYPE_CALLBACK encoderGetContentTypeCallback;
  WS_ENCODER_START_CALLBACK            encoderStartCallback;
  WS_ENCODER_ENCODE_CALLBACK           encoderEncodeCallback;
  WS_ENCODER_END_CALLBACK              encoderEndCallback;
  WS_FREE_ENCODER_CALLBACK             freeEncoderCallback;
} WS_CHANNEL_ENCODER;