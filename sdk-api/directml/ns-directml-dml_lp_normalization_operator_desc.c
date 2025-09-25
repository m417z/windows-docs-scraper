struct DML_LP_NORMALIZATION_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  UINT                  Axis;
  FLOAT                 Epsilon;
  UINT                  P;
};