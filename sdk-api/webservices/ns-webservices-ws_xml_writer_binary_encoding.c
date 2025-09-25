typedef struct _WS_XML_WRITER_BINARY_ENCODING {
  WS_XML_WRITER_ENCODING     encoding;
  WS_XML_DICTIONARY          *staticDictionary;
  WS_DYNAMIC_STRING_CALLBACK dynamicStringCallback;
  void                       *dynamicStringCallbackState;
} WS_XML_WRITER_BINARY_ENCODING;