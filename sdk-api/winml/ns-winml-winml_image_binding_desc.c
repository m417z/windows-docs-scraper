typedef struct WINML_IMAGE_BINDING_DESC {
  WINML_TENSOR_DATA_TYPE ElementType;
  UINT                   NumDimensions;
  INT64                  *pShape;
  UINT                   DataSize;
  void                   *pData;
} WINML_IMAGE_BINDING_DESC;