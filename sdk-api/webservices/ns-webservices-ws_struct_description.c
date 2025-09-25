typedef struct _WS_STRUCT_DESCRIPTION {
  ULONG                 size;
  ULONG                 alignment;
  WS_FIELD_DESCRIPTION  **fields;
  ULONG                 fieldCount;
  WS_XML_STRING         *typeLocalName;
  WS_XML_STRING         *typeNs;
  WS_STRUCT_DESCRIPTION *parentType;
  WS_STRUCT_DESCRIPTION **subTypes;
  ULONG                 subTypeCount;
  ULONG                 structOptions;
} WS_STRUCT_DESCRIPTION;