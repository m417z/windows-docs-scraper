typedef struct _WS_FIELD_DESCRIPTION {
  WS_FIELD_MAPPING mapping;
  WS_XML_STRING    *localName;
  WS_XML_STRING    *ns;
  WS_TYPE          type;
  void             *typeDescription;
  ULONG            offset;
  ULONG            options;
  WS_DEFAULT_VALUE *defaultValue;
  ULONG            countOffset;
  WS_XML_STRING    *itemLocalName;
  WS_XML_STRING    *itemNs;
  WS_ITEM_RANGE    *itemRange;
} WS_FIELD_DESCRIPTION;