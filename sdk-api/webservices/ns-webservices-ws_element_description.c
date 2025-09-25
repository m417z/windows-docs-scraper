typedef struct _WS_ELEMENT_DESCRIPTION {
  WS_XML_STRING *elementLocalName;
  WS_XML_STRING *elementNs;
  WS_TYPE       type;
  void          *typeDescription;
} WS_ELEMENT_DESCRIPTION;