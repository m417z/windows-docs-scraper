typedef struct WINML_TENSOR_BINDING_DESC {
  WINML_TENSOR_DATA_TYPE DataType;
  UINT                   NumDimensions;
  INT64                  *pShape;
  UINT                   DataSize;
  void                   *pData;
} WINML_TENSOR_BINDING_DESC;