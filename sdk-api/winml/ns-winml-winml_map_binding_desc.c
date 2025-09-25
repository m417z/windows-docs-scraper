typedef struct WINML_MAP_BINDING_DESC {
  UINT                   ElementCount;
  WINML_TENSOR_DATA_TYPE KeyType;
  union {
    LPWSTR *pStringKeys;
    INT64  *pIntKeys;
  };
  WINML_TENSOR_DATA_TYPE Fields;
  union {
    LPWSTR *pStringFields;
    INT64  *pIntFields;
    FLOAT  *pFloatFields;
    DOUBLE *pDoubleFields;
  };
} WINML_MAP_BINDING_DESC;