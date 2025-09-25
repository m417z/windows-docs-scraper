typedef struct WINML_VARIABLE_DESC {
  LPWSTR             Name;
  LPWSTR             Description;
  WINML_FEATURE_TYPE FeatureType;
  BOOL               Required;
  union {
    WINML_TENSOR_VARIABLE_DESC   Tensor;
    WINML_SEQUENCE_VARIABLE_DESC Sequence;
    WINML_MAP_VARIABLE_DESC      Map;
    WINML_IMAGE_VARIABLE_DESC    Image;
  };
} WINML_VARIABLE_DESC;