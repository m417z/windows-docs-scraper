typedef struct _WS_XML_ELEMENT_NODE {
  WS_XML_NODE      node;
  WS_XML_STRING    *prefix;
  WS_XML_STRING    *localName;
  WS_XML_STRING    *ns;
  ULONG            attributeCount;
  WS_XML_ATTRIBUTE **attributes;
  BOOL             isEmpty;
} WS_XML_ELEMENT_NODE;