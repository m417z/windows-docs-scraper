typedef struct _WS_XML_WRITER_MTOM_ENCODING {
  WS_XML_WRITER_ENCODING encoding;
  WS_XML_WRITER_ENCODING *textEncoding;
  BOOL                   writeMimeHeader;
  WS_STRING              boundary;
  WS_STRING              startInfo;
  WS_STRING              startUri;
  ULONG                  maxInlineByteCount;
} WS_XML_WRITER_MTOM_ENCODING;