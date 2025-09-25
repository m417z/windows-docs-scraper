struct DML_SLICE_GRAD_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputGradientTensor;
  const DML_TENSOR_DESC *OutputGradientTensor;
  UINT                  DimensionCount;
  const UINT            *InputWindowOffsets;
  const UINT            *InputWindowSizes;
  const INT             *InputWindowStrides;
};