typedef struct _WS_XML_READER_STREAM_INPUT {
  WS_XML_READER_INPUT input;
  WS_READ_CALLBACK    readCallback;
  void                *readCallbackState;
} WS_XML_READER_STREAM_INPUT;