struct DML_TOP_K1_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputValueTensor;
  const DML_TENSOR_DESC *OutputIndexTensor;
  UINT                  Axis;
  UINT                  K;
  DML_AXIS_DIRECTION    AxisDirection;
};