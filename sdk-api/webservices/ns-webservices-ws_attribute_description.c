typedef struct _WS_ATTRIBUTE_DESCRIPTION {
  WS_XML_STRING *attributeLocalName;
  WS_XML_STRING *attributeNs;
  WS_TYPE       type;
  void          *typeDescription;
} WS_ATTRIBUTE_DESCRIPTION;