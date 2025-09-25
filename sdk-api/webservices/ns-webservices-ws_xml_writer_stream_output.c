typedef struct _WS_XML_WRITER_STREAM_OUTPUT {
  WS_XML_WRITER_OUTPUT output;
  WS_WRITE_CALLBACK    writeCallback;
  void                 *writeCallbackState;
} WS_XML_WRITER_STREAM_OUTPUT;