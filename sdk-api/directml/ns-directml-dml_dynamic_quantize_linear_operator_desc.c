struct DML_DYNAMIC_QUANTIZE_LINEAR_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  const DML_TENSOR_DESC *OutputScaleTensor;
  const DML_TENSOR_DESC *OutputZeroPointTensor;
};