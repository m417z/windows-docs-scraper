struct DML_ACTIVATION_HARD_SIGMOID_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  FLOAT                 Alpha;
  FLOAT                 Beta;
};