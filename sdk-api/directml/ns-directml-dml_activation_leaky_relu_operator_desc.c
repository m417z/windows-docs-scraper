struct DML_ACTIVATION_LEAKY_RELU_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  FLOAT                 Alpha;
};