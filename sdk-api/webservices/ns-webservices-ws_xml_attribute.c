typedef struct _WS_XML_ATTRIBUTE {
  BYTE          singleQuote;
  BYTE          isXmlNs;
  WS_XML_STRING *prefix;
  WS_XML_STRING *localName;
  WS_XML_STRING *ns;
  WS_XML_TEXT   *value;
} WS_XML_ATTRIBUTE;