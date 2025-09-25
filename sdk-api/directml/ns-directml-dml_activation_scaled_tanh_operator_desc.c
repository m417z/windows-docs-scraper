struct DML_ACTIVATION_SCALED_TANH_OPERATOR_DESC {
  const DML_TENSOR_DESC *InputTensor;
  const DML_TENSOR_DESC *OutputTensor;
  FLOAT                 Alpha;
  FLOAT                 Beta;
};