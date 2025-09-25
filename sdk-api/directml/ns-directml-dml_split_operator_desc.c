struct DML_SPLIT_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  UINT                  OutputCount;
  const DML_TENSOR_DESC *OutputTensors;
  UINT                  Axis;
};