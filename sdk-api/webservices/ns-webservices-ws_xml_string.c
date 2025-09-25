typedef struct _WS_XML_STRING {
  ULONG             length;
  BYTE              *bytes;
  WS_XML_DICTIONARY *dictionary;
  ULONG             id;
} WS_XML_STRING;