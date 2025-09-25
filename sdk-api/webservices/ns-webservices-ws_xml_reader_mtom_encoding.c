typedef struct _WS_XML_READER_MTOM_ENCODING {
  WS_XML_READER_ENCODING encoding;
  WS_XML_READER_ENCODING *textEncoding;
  BOOL                   readMimeHeader;
  WS_STRING              startInfo;
  WS_STRING              boundary;
  WS_STRING              startUri;
} WS_XML_READER_MTOM_ENCODING;