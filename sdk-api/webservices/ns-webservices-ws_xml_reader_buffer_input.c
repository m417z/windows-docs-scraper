typedef struct _WS_XML_READER_BUFFER_INPUT {
  WS_XML_READER_INPUT input;
  void                *encodedData;
  ULONG               encodedDataSize;
} WS_XML_READER_BUFFER_INPUT;