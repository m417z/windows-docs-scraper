struct DML_ACTIVATION_SHRINK_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  FLOAT                 Bias;
  FLOAT                 Threshold;
};