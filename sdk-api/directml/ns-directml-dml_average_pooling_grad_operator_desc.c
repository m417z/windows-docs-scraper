struct DML_AVERAGE_POOLING_GRAD_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputGradientTensor;
  const DML_TENSOR_DESC *OutputGradientTensor;
  UINT                  DimensionCount;
  const UINT            *Strides;
  const UINT            *WindowSize;
  const UINT            *StartPadding;
  const UINT            *EndPadding;
  BOOL                  IncludePadding;
};