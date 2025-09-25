struct DML_CONVOLUTION_OPERATOR_DESC {
  const DML_TENSOR_DESC     *InputTensor;
  const DML_TENSOR_DESC     *FilterTensor;
  const DML_TENSOR_DESC     *BiasTensor;
  const DML_TENSOR_DESC     *OutputTensor;
  DML_CONVOLUTION_MODE      Mode;
  DML_CONVOLUTION_DIRECTION Direction;
  UINT                      DimensionCount;
  const UINT                *Strides;
  const UINT                *Dilations;
  const UINT                *StartPadding;
  const UINT                *EndPadding;
  const UINT                *OutputPadding;
  UINT                      GroupCount;
  const DML_OPERATOR_DESC   *FusedActivation;
};