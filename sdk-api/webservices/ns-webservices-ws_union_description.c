typedef struct _WS_UNION_DESCRIPTION {
  ULONG                      size;
  ULONG                      alignment;
  WS_UNION_FIELD_DESCRIPTION **fields;
  ULONG                      fieldCount;
  ULONG                      enumOffset;
  int                        noneEnumValue;
  ULONG                      *valueIndices;
} WS_UNION_DESCRIPTION;