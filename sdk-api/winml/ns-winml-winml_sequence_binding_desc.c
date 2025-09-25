typedef struct WINML_SEQUENCE_BINDING_DESC {
  UINT                   ElementCount;
  WINML_TENSOR_DATA_TYPE ElementType;
  union {
    LPWSTR *pStrings;
    INT64  *pInts;
    FLOAT  *pFloats;
    DOUBLE *pDoubles;
  };
} WINML_SEQUENCE_BINDING_DESC;