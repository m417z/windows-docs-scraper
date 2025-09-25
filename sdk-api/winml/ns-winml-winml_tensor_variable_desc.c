typedef struct WINML_TENSOR_VARIABLE_DESC {
  WINML_TENSOR_DATA_TYPE ElementType;
  UINT                   NumDimensions;
  INT64                  *pShape;
} WINML_TENSOR_VARIABLE_DESC;