typedef struct _WS_ENUM_DESCRIPTION {
  WS_ENUM_VALUE *values;
  ULONG         valueCount;
  ULONG         maxByteCount;
  ULONG         *nameIndices;
} WS_ENUM_DESCRIPTION;