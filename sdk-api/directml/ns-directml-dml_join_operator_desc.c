struct DML_JOIN_OPERATOR_DESC {
  UINT                  InputCount;
  const DML_TENSOR_DESC *InputTensors;
  const DML_TENSOR_DESC *OutputTensor;
  UINT                  Axis;
};