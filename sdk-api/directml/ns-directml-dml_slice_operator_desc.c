struct DML_SLICE_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  UINT                  DimensionCount;
  const UINT            *Offsets;
  const UINT            *Sizes;
  const UINT            *Strides;
};