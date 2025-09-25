typedef struct _WS_XML_LIST_TEXT {
  WS_XML_TEXT text;
  ULONG       itemCount;
  WS_XML_TEXT **items;
} WS_XML_LIST_TEXT;