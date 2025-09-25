struct DML_BUFFER_TENSOR_DESC {
  DML_TENSOR_DATA_TYPE DataType;
  DML_TENSOR_FLAGS     Flags;
  UINT                 DimensionCount;
  const UINT           *Sizes;
  const UINT           *Strides;
  UINT64               TotalTensorSizeInBytes;
  UINT                 GuaranteedBaseOffsetAlignment;
};