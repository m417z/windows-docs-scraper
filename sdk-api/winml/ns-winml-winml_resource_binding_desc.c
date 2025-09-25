typedef struct WINML_RESOURCE_BINDING_DESC {
  WINML_TENSOR_DATA_TYPE ElementType;
  UINT                   NumDimensions;
  INT64                  *pShape;
  ID3D12Resource         *pResource;
} WINML_RESOURCE_BINDING_DESC;