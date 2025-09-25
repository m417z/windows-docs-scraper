struct DML_ELEMENT_WISE_DEQUANTIZE_LINEAR_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *ScaleTensor;
  const DML_TENSOR_DESC *ZeroPointTensor;
  const DML_TENSOR_DESC *OutputTensor;
};