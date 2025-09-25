typedef struct WINML_IMAGE_VARIABLE_DESC {
  WINML_TENSOR_DATA_TYPE ElementType;
  UINT                   NumDimensions;
  INT64                  *pShape;
} WINML_IMAGE_VARIABLE_DESC;