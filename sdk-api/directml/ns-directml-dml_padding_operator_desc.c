struct DML_PADDING_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  DML_PADDING_MODE      PaddingMode;
  FLOAT                 PaddingValue;
  UINT                  DimensionCount;
  const UINT            *StartPadding;
  const UINT            *EndPadding;
};