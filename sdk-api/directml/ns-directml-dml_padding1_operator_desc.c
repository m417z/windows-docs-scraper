struct DML_PADDING1_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  DML_PADDING_MODE      PaddingMode;
  DML_TENSOR_DATA_TYPE  PaddingValueDataType;
  DML_SCALAR_UNION      PaddingValue;
  UINT                  DimensionCount;
  const UINT            *StartPadding;
  const UINT            *EndPadding;
};