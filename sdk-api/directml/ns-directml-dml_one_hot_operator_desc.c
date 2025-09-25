struct DML_ONE_HOT_OPERATOR_DESC {
  const DML_TENSOR_DESC *IndicesTensor;
  const DML_TENSOR_DESC *ValuesTensor;
  const DML_TENSOR_DESC *OutputTensor;
  UINT                  Axis;
};